// c5d-cflags: +/GS-
#include "sqlite3_api.h"
#include "Database/Connection.h"

// src: GUESS [0x10001b20] (confidence: high)
int Sprintf512_10001b20(char* dst, const char* fmt, ...);
// src: GUESS [0x10001b40] (confidence: high)
int Sprintf1024_10001b40(char* dst, const char* fmt, ...);

namespace Database {

// src: EXE [0x10002940]
bool Connection::ValidateFKConstraints(bool bValidate) const {
    bool bValid = true;
    IDatabaseLogger* pLogger = m_pLogger;
    if (pLogger != 0) {
        pLogger->LogMessage("Validating Foreign Key Constraints...", 0);
    }

    sqlite3_stmt* pTableStmt;
    if (sqlite3_prepare_v2(m_pDb, "select name from sqlite_master where type = 'table'", -1, &pTableStmt, 0) != 0) {
        return false;
    }

    while (sqlite3_step(pTableStmt) == 100) {
        const unsigned char* szTable = sqlite3_column_text(pTableStmt, 0);
        char szPragmaSQL[512];
        Sprintf512_10001b20(szPragmaSQL, "pragma foreign_key_list(%s);", szTable);

        sqlite3_stmt* pFkStmt;
        if (sqlite3_prepare_v2(m_pDb, szPragmaSQL, -1, &pFkStmt, 0) != 0) {
            sqlite3_finalize(pTableStmt);
            bValid = false;
            goto done;
        }

        while (sqlite3_step(pFkStmt) == 100) {
            const unsigned char* szRefTable = sqlite3_column_text(pFkStmt, 2);
            const unsigned char* szFromCol = sqlite3_column_text(pFkStmt, 3);
            const unsigned char* szToCol = sqlite3_column_text(pFkStmt, 4);

            char szCheckSQL[512];
            Sprintf512_10001b20(
                szCheckSQL,
                "select \"%s\" from %s where %s not null and %s not in (select \"%s\" from %s);",
                szFromCol,
                szTable,
                szFromCol,
                szFromCol,
                szToCol,
                szRefTable);

            sqlite3_stmt* pCheckStmt;
            if (sqlite3_prepare_v2(m_pDb, szCheckSQL, -1, &pCheckStmt, 0) != 0) {
                char szErr[512];
                Sprintf512_10001b20(szErr, "Failure to check references for foreign key %s(%s).", szTable, szFromCol);
                IDatabaseLogger* pErrLogger = m_pLogger;
                if (pErrLogger != 0) {
                    pErrLogger->LogMessage(szErr, 2);
                }
                const char* szDbErr = sqlite3_errmsg(m_pDb);
                IDatabaseLogger* pDbErrLogger = m_pLogger;
                if (pDbErrLogger != 0) {
                    pDbErrLogger->LogMessage(szDbErr, 2);
                }
                sqlite3_finalize(pTableStmt);
                sqlite3_finalize(pFkStmt);
                bValid = false;
                goto done;
            }

            if (sqlite3_step(pCheckStmt) == 100) {
                bValid = false;
                do {
                    const unsigned char* szBadVal = sqlite3_column_text(pCheckStmt, 0);
                    char szMsg[1024];
                    Sprintf1024_10001b40(szMsg, "Invalid Reference on %s.%s - \"%s\" does not exist in %s", szTable, szFromCol, szBadVal, szRefTable);
                    IDatabaseLogger* pMsgLogger = m_pLogger;
                    if (pMsgLogger != 0) {
                        pMsgLogger->LogMessage(szMsg, 2);
                    }
                } while (sqlite3_step(pCheckStmt) == 100);
            }
            sqlite3_finalize(pCheckStmt);
        }
        sqlite3_finalize(pFkStmt);
    }

    sqlite3_finalize(pTableStmt);

done:
    const char* szResult = bValid ? "Passed Validation." : "Failed Validation.";
    IDatabaseLogger* pEndLogger = m_pLogger;
    if (pEndLogger != 0) {
        pEndLogger->LogMessage(szResult, 0);
    }
    return bValid;
}

}  // namespace Database
