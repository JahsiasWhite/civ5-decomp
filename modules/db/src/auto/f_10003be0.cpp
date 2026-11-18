#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

void Connection::Analyze() const {
    if (m_pDb != 0) {
        if (sqlite3_exec(m_pDb, "ANALYZE", 0, 0, 0) != 0) {
            const char* szErr = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
            IDatabaseLogger* pLogger = m_pLogger;
            if (pLogger != 0) {
                pLogger->LogMessage(szErr, 2);
            }
        }
    }
}

}  // namespace Database
