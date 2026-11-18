#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

__int64 Results::GetInt64(int iColumn) {
    return m_Command.stmt ? sqlite3_column_int64(m_Command.stmt, iColumn) : 0;
}

}  // namespace Database
