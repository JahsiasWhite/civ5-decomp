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
    // src: EXE [0x10007520]
    CVGAMEDATABASE_API virtual ~Results();
    // src: EXE [0x100066f0]
    CVGAMEDATABASE_API virtual const char* GetColumns() const;

    // src: EXE [0x10006740]
    CVGAMEDATABASE_API bool Reset();
    // src: EXE [0x10006770]
    CVGAMEDATABASE_API bool TryReset();
    // src: EXE [0x10006930]
    CVGAMEDATABASE_API bool Bind(int iColumn, double dValue);
    // src: EXE [0x10006960]
    CVGAMEDATABASE_API bool Bind(int iColumn, float fValue);
    // src: EXE [0x10006990]
    CVGAMEDATABASE_API bool Bind(int iColumn, int iValue);
    // src: EXE [0x100069b0]
    CVGAMEDATABASE_API bool Bind(int iColumn, __int64 iValue);
    // src: EXE [0x100069e0]
    CVGAMEDATABASE_API bool BindNULL(int iColumn);
    // src: EXE [0x10006a00]
    CVGAMEDATABASE_API int ColumnCount() const;
    // src: EXE [0x10006a20]
    CVGAMEDATABASE_API const char* ColumnName(int iColumn);
    CVGAMEDATABASE_API int ColumnPosition(const char* szColumn);

    // src: EXE [0x10006ac0]
    CVGAMEDATABASE_API const char* GetText(int iColumn);
    // src: EXE [0x10006ae0]
    CVGAMEDATABASE_API const wchar_t* GetText16(int iColumn);
    // src: EXE [0x10006b00]
    CVGAMEDATABASE_API int GetInt(int iColumn);
    // src: EXE [0x10006b20]
    CVGAMEDATABASE_API __int64 GetInt64(int iColumn);
    // src: EXE [0x10006b40]
    CVGAMEDATABASE_API float GetFloat(int iColumn);
    // src: EXE [0x10006b70]
    CVGAMEDATABASE_API double GetDouble(int iColumn);
    // src: EXE [0x10006be0]
    CVGAMEDATABASE_API void GetValue(int iColumn, int& iValue);
    // src: EXE [0x10006ce0]
    CVGAMEDATABASE_API void GetValue(int iColumn, const char*& szValue);
    // src: EXE [0x10006d10]
    CVGAMEDATABASE_API void GetValue(int iColumn, const wchar_t*& wszValue);

    CVGAMEDATABASE_API const char* GetText(const char* szColumn);
    CVGAMEDATABASE_API int GetInt(const char* szColumn);

    CVGAMEDATABASE_API bool SingleQuery() const;
    // src: EXE [0x10006d50]
    CVGAMEDATABASE_API void SingleQuery(bool bSingleQuery);

private:
    Command m_Command;                 // +0x04
    const char* m_szColumns;           // +0x0c
    bool m_bSingleQuery;               // +0x10
    // +0x14: the column-name -> position hash map (not modelled yet)
};

}  // namespace Database
