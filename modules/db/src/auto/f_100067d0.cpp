#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, const char* szValue, int iLength, bool bStatic) {
    if (bStatic) {
        return !sqlite3_bind_text(m_Command.stmt, iColumn, szValue, iLength, (void (*)(void*))-1);
    }
    return !sqlite3_bind_text(m_Command.stmt, iColumn, szValue, iLength, 0);
}

}  // namespace Database
