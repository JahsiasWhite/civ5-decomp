#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::BindNULL(int iColumn) {
    return sqlite3_bind_null(m_Command.stmt, iColumn) == 0;
}

}  // namespace Database
