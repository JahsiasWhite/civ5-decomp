#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, const char*& szValue) {
    szValue = m_Command.stmt ? reinterpret_cast<const char*>(sqlite3_column_text(m_Command.stmt, iColumn)) : 0;
}

}  // namespace Database
