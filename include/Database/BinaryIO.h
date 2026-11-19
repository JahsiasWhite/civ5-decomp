// Database::BinaryIO: saves and loads a SQLite Database::Connection to/from a binary file.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

class Connection;

// src: EXE
class BinaryIO {
public:
    // src: EXE [0x100062d0]
    CVGAMEDATABASE_API BinaryIO(const char* szFilename);
    // src: EXE [0x100063c0]
    CVGAMEDATABASE_API bool Load(Connection& kConnection);

private:
    // src: GUESS (confidence: high)
    const char* m_szFilename;  // +0
};

}  // namespace Database
