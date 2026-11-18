#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, double& dValue) {
    dValue = m_Command.stmt ? sqlite3_column_double(m_Command.stmt, iColumn) : 0.0;
}

}  // namespace Database
