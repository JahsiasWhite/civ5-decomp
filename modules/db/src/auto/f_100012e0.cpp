#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

int Connection::StatementCount() const {
    int iCount = 0;
    for (sqlite3_stmt* pStmt = sqlite3_next_stmt(m_pDb, 0); pStmt != 0; pStmt = sqlite3_next_stmt(m_pDb, pStmt)) {
        ++iCount;
    }
    return iCount;
}

}  // namespace Database
