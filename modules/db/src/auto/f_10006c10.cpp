#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, __int64& iValue) {
    iValue = m_Command.stmt ? sqlite3_column_int64(m_Command.stmt, iColumn) : 0;
}

}  // namespace Database
