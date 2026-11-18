// src: EXE [0x10003ad0]
#include "Database/Connection.h"
#include "sqlite3_api.h"
#include <string.h>

namespace Database {

bool Connection::ExecuteMultiple(const char* szStatements, int iLength) const {
    if (iLength < 0) {
        iLength = (int)strlen(szStatements);
    }
    sqlite3_stmt* pStmt = 0;
    const char* pTail = szStatements;
    int rc = sqlite3_prepare_v2(m_pDb, szStatements, iLength, &pStmt, &pTail);
    if (pStmt != 0) {
        do {
            iLength += (int)(szStatements - pTail);
            do {
                rc = sqlite3_step(pStmt);
            } while (rc == 0 || rc == 100);
            if (sqlite3_finalize(pStmt) != 0) {
                const char* szErr = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
                IDatabaseLogger* pLogger = m_pLogger;
                if (pLogger != 0) {
                    pLogger->LogMessage(szErr, 2);
                }
            }
            if (rc != 101) {
                const char* szErr = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
                IDatabaseLogger* pLogger = m_pLogger;
                if (pLogger != 0) {
                    pLogger->LogMessage(szErr, 2);
                }
                return false;
            }
            szStatements = pTail;
            rc = sqlite3_prepare_v2(m_pDb, szStatements, iLength, &pStmt, &pTail);
        } while (pStmt != 0);
    }
    if (rc == 0 || rc == 101) {
        return true;
    }
    const char* szErr = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
    IDatabaseLogger* pLogger = m_pLogger;
    if (pLogger != 0) {
        pLogger->LogMessage(szErr, 2);
    }
    return false;
}

}  // namespace Database
