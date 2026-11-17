#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::SingleQuery() const {
    return m_bSingleQuery;
}

const char* Results::GetText(const char* szColumn) {
    int iColumn = ColumnPosition(szColumn);
    if (m_Command.stmt != 0)
        return (const char*)sqlite3_column_text(m_Command.stmt, iColumn);
    return 0;
}

int Results::GetInt(const char* szColumn) {
    int iColumn = ColumnPosition(szColumn);
    if (m_Command.stmt != 0)
        return sqlite3_column_int(m_Command.stmt, iColumn);
    return 0;
}

}  // namespace Database
