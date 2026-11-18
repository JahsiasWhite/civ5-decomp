#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

bool Connection::SetBusyTimeout(int iTimeOut) {
    if (sqlite3_busy_timeout(m_pDb, iTimeOut) == 0) {
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
