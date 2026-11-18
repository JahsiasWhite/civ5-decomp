#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, float& fValue) {
    fValue = m_Command.stmt ? (float)sqlite3_column_double(m_Command.stmt, iColumn) : 0.0f;
}

}  // namespace Database
