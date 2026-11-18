#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

const char* Connection::StatementSQL(int iIndex) const {
    sqlite3_stmt* pStmt = sqlite3_next_stmt(m_pDb, 0);
    if (pStmt != 0) {
        int idx = iIndex;
        do {
            if (idx == 0) {
                return sqlite3_sql(pStmt);
            }
            --idx;
            pStmt = sqlite3_next_stmt(m_pDb, pStmt);
        } while (pStmt != 0);
    }
    return 0;
}

}  // namespace Database
