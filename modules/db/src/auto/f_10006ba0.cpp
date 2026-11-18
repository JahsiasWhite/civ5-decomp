#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, bool& bValue) {
    bValue = (m_Command.stmt ? sqlite3_column_int(m_Command.stmt, iColumn) : 0) != 0;
}

}  // namespace Database
