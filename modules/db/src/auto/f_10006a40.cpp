// src: EXE [0x10006a40]
#include "Database/Results.h"
#include "sqlite3_api.h"
#include <string.h>

namespace Database {

ColumnTypes Results::ColumnType(int iColumn) {
    if (m_Command.stmt != 0) {
        ColumnTypes eType = (ColumnTypes)sqlite3_column_type(m_Command.stmt, iColumn);
        if (eType == CT_INTEGER) {
            const char* szDeclType = sqlite3_column_decltype(m_Command.stmt, iColumn);
            if (szDeclType != 0 && strcmp(szDeclType, "boolean") == 0) {
                eType = CT_BOOL;
            }
        }
        return eType;
    }
    return CT_NONE;
}

}  // namespace Database
