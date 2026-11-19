// Database::ResultsCache: prepared statements kept per SQL string, all on one connection.
// Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "DatabaseAPI.h"
#include <string>
#include <hash_map>

namespace Database {

class Connection;
class Results;

class ResultsCache {
public:
    CVGAMEDATABASE_API Connection& Connection();
    // src: EXE [0x1000db30]
    CVGAMEDATABASE_API void Clear();
    // src: EXE [0x1000dd80]
    CVGAMEDATABASE_API Results* Prepare(const std::string& strKey, const char* szSQL, int iLength);

private:
    Database::Connection& m_db;                        // +0
    // src: GUESS (confidence: high)
    stdext::hash_map<std::string, Results*> m_results; // +4
};

}  // namespace Database
