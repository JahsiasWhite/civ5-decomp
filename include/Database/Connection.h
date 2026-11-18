// Database::Connection: SQLite database connection wrapper.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

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
    // src: EXE [0x10002bd0]
    CVGAMEDATABASE_API bool SetBusyTimeout(int iTimeOut);
    // src: EXE [0x100034e0]
    CVGAMEDATABASE_API bool Open(const char* szFileName, int iFlags);
    // src: EXE [0x10003be0]
    CVGAMEDATABASE_API void Analyze() const;
    // src: EXE [0x10003c30]
    CVGAMEDATABASE_API void Vacuum() const;

private:
    // src: GUESS (confidence: high)
    sqlite3* m_pDb;             // +0x00
    char m_pad04[0x74];         // +0x04
    // src: GUESS (confidence: high)
    IDatabaseLogger* m_pLogger; // +0x78
};

}  // namespace Database
