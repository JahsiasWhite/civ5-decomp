#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, float fValue) {
    return sqlite3_bind_double(m_Command.stmt, iColumn, fValue) == 0;
}

}  // namespace Database
