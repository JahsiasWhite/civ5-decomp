#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, int iValue) {
    return sqlite3_bind_int(m_Command.stmt, iColumn, iValue) == 0;
}

}  // namespace Database
