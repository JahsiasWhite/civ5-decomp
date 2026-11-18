#include "Database/Connection.h"
#include "sqlite3_api.h"

// src: GUESS (confidence: low)
extern "C" void sqlite3_trace(sqlite3* db, void (*xTrace)(void*, const char*), void* pArg);
// src: GUESS (confidence: low)
void TraceCallback_10003470(void* pArg, const char* zSql);

namespace Database {

bool Connection::Open(const char* szFileName, int iFlags) {
    if (szFileName == 0) {
        szFileName = ":memory:";
    }
    if (sqlite3_open_v2(szFileName, &m_pDb, iFlags, 0) != 0) {
        const char* szErr = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
        IDatabaseLogger* pLogger = m_pLogger;
        if (pLogger != 0) {
            pLogger->LogMessage(szErr, 2);
        }
        return false;
    }
    sqlite3_trace(m_pDb, &TraceCallback_10003470, this);
    return true;
}

}  // namespace Database
