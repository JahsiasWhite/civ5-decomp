// Database::Connection: SQLite database connection wrapper.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

// src: EXE
class IDatabaseLogger {
public:
    virtual void Slot0() = 0;
    // src: GUESS (confidence: medium)
    virtual void LogMessage(const char* szMessage, int iLevel) = 0;
};

// src: EXE
class Connection {
public:
    // src: EXE [0x10001190]
    CVGAMEDATABASE_API int TotalChanges() const;
    // src: EXE [0x10001390]
    CVGAMEDATABASE_API int ErrorCode() const;
    // src: EXE [0x100013b0]
    CVGAMEDATABASE_API const char* ErrorMessage() const;
    // src: EXE [0x100028a0]
    CVGAMEDATABASE_API void LogMessage(const char* szMessage) const;
    // src: EXE [0x100028c0]
    CVGAMEDATABASE_API void LogWarning(const char* szMessage) const;
    // src: EXE [0x100028e0]
    CVGAMEDATABASE_API void LogError(const char* szMessage) const;

private:
    // src: GUESS (confidence: high)
    sqlite3* m_pDb;             // +0x00
    char m_pad04[0x74];         // +0x04
    // src: GUESS (confidence: high)
    IDatabaseLogger* m_pLogger; // +0x78
};

}  // namespace Database
