#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, const char* szValue, bool bStatic) {
    if (bStatic) {
        if (sqlite3_bind_text(m_Command.stmt, iColumn, szValue, -1, (void (*)(void*))-1) == 0) {
            return true;
        }
        return false;
    }
    if (sqlite3_bind_text(m_Command.stmt, iColumn, szValue, -1, 0) == 0) {
        return true;
    }
    return false;
}

}  // namespace Database
