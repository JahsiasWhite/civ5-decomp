#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

float Results::GetFloat(int iColumn) {
    return m_Command.stmt ? (float)sqlite3_column_double(m_Command.stmt, iColumn) : 0.0f;
}

}  // namespace Database
