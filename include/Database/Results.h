// Database::Results: the rows of one prepared SQLite statement, read by column name or
// index. Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "DatabaseAPI.h"
#include <string>
#include <hash_map>

namespace Database {

// src: EXE [0x10006a40]
enum ColumnTypes {
    CT_INTEGER = 1,
    CT_FLOAT = 2,
    CT_TEXT = 3,
    CT_BLOB = 4,
    CT_NONE = 5,
    CT_BOOL = 6
};

// The connection a statement was prepared on, and the statement.
struct Command {
    const Connection* connection;      // +0
    sqlite3_stmt* stmt;                // +4
};

class Results {
public:
    // src: EXE [0x10006d60]
    CVGAMEDATABASE_API static void* operator new(unsigned int uiSize);
    // src: EXE [0x10007cd0]
    CVGAMEDATABASE_API Results(const char* szColumns);
    // src: EXE [0x10007af0]
    CVGAMEDATABASE_API Results(const Results& kOther);
    // src: EXE [0x10007520]
    CVGAMEDATABASE_API virtual ~Results();
    // src: EXE [0x100066f0]
    CVGAMEDATABASE_API virtual const char* GetColumns() const;

    // src: EXE [0x10006700]
    CVGAMEDATABASE_API void SetColumns(const char* szColumns);
    // src: EXE [0x10006740]
    CVGAMEDATABASE_API bool Reset();
    // src: EXE
    CVGAMEDATABASE_API bool Step();
    // src: EXE [0x10006770]
    CVGAMEDATABASE_API bool TryReset();
    // src: EXE [0x10006f30]
    CVGAMEDATABASE_API bool TryExecute();
    // src: EXE
    CVGAMEDATABASE_API void Release();
    // src: EXE [0x100067d0]
    CVGAMEDATABASE_API bool Bind(int iColumn, const char* szValue, int iLength, bool bStatic);
    // src: EXE [0x10006830]
    CVGAMEDATABASE_API bool Bind(int iColumn, const char* szValue, bool bStatic);
    // src: EXE [0x10006880]
    CVGAMEDATABASE_API bool Bind(int iColumn, const wchar_t* wszValue, int iLength, bool bStatic);
    // src: EXE [0x100068e0]
    CVGAMEDATABASE_API bool Bind(int iColumn, const wchar_t* wszValue, bool bStatic);
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
    // src: EXE [0x10006a40]
    CVGAMEDATABASE_API ColumnTypes ColumnType(int iColumn);

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
    // src: EXE [0x100070c0]
    CVGAMEDATABASE_API bool GetBool(int iColumn);
    // src: EXE [0x10006ba0]
    CVGAMEDATABASE_API void GetValue(int iColumn, bool& bValue);
    // src: EXE [0x10006be0]
    CVGAMEDATABASE_API void GetValue(int iColumn, int& iValue);
    // src: EXE [0x10006c10]
    CVGAMEDATABASE_API void GetValue(int iColumn, __int64& iValue);
    // src: EXE [0x10006c50]
    CVGAMEDATABASE_API void GetValue(int iColumn, float& fValue);
    // src: EXE [0x10006c90]
    CVGAMEDATABASE_API void GetValue(int iColumn, double& dValue);
    // src: EXE [0x10006ce0]
    CVGAMEDATABASE_API void GetValue(int iColumn, const char*& szValue);
    // src: EXE [0x10006d10]
    CVGAMEDATABASE_API void GetValue(int iColumn, const wchar_t*& wszValue);

    CVGAMEDATABASE_API const char* GetText(const char* szColumn);
    CVGAMEDATABASE_API int GetInt(const char* szColumn);

    CVGAMEDATABASE_API bool SingleQuery() const;
    // src: EXE [0x10006d50]
    CVGAMEDATABASE_API void SingleQuery(bool bSingleQuery);

protected:
    // src: EXE [0x10007d30]
    CVGAMEDATABASE_API void HashColumnPositions();

private:
    Command m_Command;                 // +0x04
    const char* m_szColumns;           // +0x0c
    bool m_bSingleQuery;               // +0x10
    // src: GUESS (confidence: high)
    stdext::hash_map<std::string, unsigned int> m_columnPositions; // +0x14
};

}  // namespace Database
