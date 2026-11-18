#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

void Results::GetValue(int iColumn, const wchar_t*& wszValue) {
    wszValue = m_Command.stmt ? reinterpret_cast<const wchar_t*>(sqlite3_column_text16(m_Command.stmt, iColumn)) : 0;
}

}  // namespace Database
