#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

int Results::GetInt(int iColumn) {
    return m_Command.stmt ? sqlite3_column_int(m_Command.stmt, iColumn) : 0;
}

}  // namespace Database
