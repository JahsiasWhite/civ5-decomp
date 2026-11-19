// Database::Connection: SQLite database connection wrapper.
#pragma once
#include "DatabaseAPI.h"
#include <string>
#include <hash_map>

namespace Database {

class Results;

// src: EXE
class IDatabaseLogger {
public:
    // src: GUESS (confidence: high)
    virtual ~IDatabaseLogger() {}
    // src: GUESS (confidence: medium)
    virtual void LogMessage(const char* szMessage, int iLevel) = 0;
};

// src: EXE
class Connection {
public:
    // src: EXE [0x10005f70]
    CVGAMEDATABASE_API Connection(const char* szFileName, int iFlags);
    // src: EXE [0x10005fe0]
    CVGAMEDATABASE_API ~Connection();
    // src: EXE [0x10005b90]
    CVGAMEDATABASE_API void Close();
    // src: EXE [0x10005c90]
    CVGAMEDATABASE_API void ClearCountCache();
    // src: EXE [0x10006070]
    CVGAMEDATABASE_API int Count(const char* szTable, bool bCache);
    // src: EXE [0x10001190]
    CVGAMEDATABASE_API int TotalChanges() const;
    // src: EXE [0x100012e0]
    CVGAMEDATABASE_API int StatementCount() const;
    // src: EXE [0x10001310]
    CVGAMEDATABASE_API const char* StatementSQL(int iIndex) const;
    // src: EXE [0x10001390]
    CVGAMEDATABASE_API int ErrorCode() const;
    // src: EXE [0x100013b0]
    CVGAMEDATABASE_API const char* ErrorMessage() const;
    // src: EXE [0x10002860]
    CVGAMEDATABASE_API void SetLogger(IDatabaseLogger* pLogger);
    // src: EXE [0x100028a0]
    CVGAMEDATABASE_API void LogMessage(const char* szMessage) const;
    // src: EXE [0x100028c0]
    CVGAMEDATABASE_API void LogWarning(const char* szMessage) const;
    // src: EXE [0x100028e0]
    CVGAMEDATABASE_API void LogError(const char* szMessage) const;
    // src: EXE [0x10002940]
    CVGAMEDATABASE_API bool ValidateFKConstraints(bool bValidate) const;
    // src: EXE [0x10002bd0]
    CVGAMEDATABASE_API bool SetBusyTimeout(int iTimeOut);
    // src: EXE [0x100034e0]
    CVGAMEDATABASE_API bool Open(const char* szFileName, int iFlags);
    // src: EXE [0x10003550]
    CVGAMEDATABASE_API bool SelectAt(Results& kResults, const char* szTable, int iRowID);
    // src: EXE [0x100035f0]
    CVGAMEDATABASE_API bool SelectAt(Results& kResults, const char* szTable, const char* szColumn, const char* szValue);
    // src: EXE [0x100036b0]
    CVGAMEDATABASE_API bool SelectAt(Results& kResults, const char* szTable, const char* szColumn, int iValue);
    // src: EXE [0x10003770]
    CVGAMEDATABASE_API bool SelectAt(Results& kResults, const char* szTable, const char* szColumn, double dValue);
    // src: EXE [0x10003840]
    CVGAMEDATABASE_API bool SelectAll(Results& kResults, const char* szTable);
    // src: EXE [0x100038f0]
    CVGAMEDATABASE_API bool SelectWhere(Results& kResults, const char* szTable, const char* szWhere);
    // src: EXE [0x100039b0]
    CVGAMEDATABASE_API bool Execute(Results& kResults, const char* szSQL, int iLength) const;
    // src: EXE [0x10003a00]
    CVGAMEDATABASE_API bool Execute(const char* szSQL, int iLength) const;
    // src: EXE [0x10003ad0]
    CVGAMEDATABASE_API bool ExecuteMultiple(const char* szStatements, int iLength) const;
    // src: EXE [0x10003be0]
    CVGAMEDATABASE_API void Analyze() const;
    // src: EXE [0x10003c30]
    CVGAMEDATABASE_API void Vacuum() const;
    // src: EXE [0x100044a0]
    CVGAMEDATABASE_API void BeginTransaction();
    // src: EXE [0x100044b0]
    CVGAMEDATABASE_API void EndTransaction();
    // src: EXE [0x100044c0]
    CVGAMEDATABASE_API void RollbackTransaction();

private:
    // src: GUESS (confidence: high)
    sqlite3* m_pDb;                                     // +0x00
    // src: GUESS (confidence: high)
    std::string m_strFileName;                          // +0x04
    // src: GUESS (confidence: medium)
    stdext::hash_map<std::string, int> m_map1;          // +0x20
    // src: GUESS (confidence: medium)
    stdext::hash_map<std::string, unsigned int> m_map2; // +0x4c
    // src: GUESS (confidence: high)
    IDatabaseLogger* m_pLogger;                         // +0x78
};

}  // namespace Database
