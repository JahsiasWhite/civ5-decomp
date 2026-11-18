#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

const char* Results::GetText(int iColumn) {
    return m_Command.stmt ? (const char*)sqlite3_column_text(m_Command.stmt, iColumn) : 0;
}

}  // namespace Database
