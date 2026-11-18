// Database::BinaryIO: saves and loads a SQLite Database::Connection to/from a binary file.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

// src: EXE
class BinaryIO {
public:
    // src: EXE [0x100062d0]
    CVGAMEDATABASE_API BinaryIO(const char* szFilename);

private:
    // src: GUESS (confidence: high)
    const char* m_szFilename;  // +0
};

}  // namespace Database
