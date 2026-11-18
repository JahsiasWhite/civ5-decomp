#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, double dValue) {
    return sqlite3_bind_double(m_Command.stmt, iColumn, dValue) == 0;
}

}  // namespace Database
