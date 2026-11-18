#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

const wchar_t* Results::GetText16(int iColumn) {
    return m_Command.stmt ? (const wchar_t*)sqlite3_column_text16(m_Command.stmt, iColumn) : 0;
}

}  // namespace Database
