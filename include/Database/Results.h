// Database::Results: the rows of one prepared SQLite statement, read by column name or
// index. Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

// The connection a statement was prepared on, and the statement.
struct Command {
    const Connection* connection;      // +0
    sqlite3_stmt* stmt;                // +4
};

class Results {
public:
    CVGAMEDATABASE_API virtual ~Results();

    CVGAMEDATABASE_API int ColumnPosition(const char* szColumn);

    CVGAMEDATABASE_API const char* GetText(const char* szColumn);
    CVGAMEDATABASE_API int GetInt(const char* szColumn);

    CVGAMEDATABASE_API bool SingleQuery() const;

private:
    Command m_Command;                 // +0x04
    const char* m_szColumns;           // +0x0c
    bool m_bSingleQuery;               // +0x10
    // +0x14: the column-name -> position hash map (not modelled yet)
};

}  // namespace Database
