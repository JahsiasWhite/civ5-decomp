// Database::ResultsCache: prepared statements kept per SQL string, all on one connection.
// Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

class ResultsCache {
public:
    CVGAMEDATABASE_API Connection& Connection();

private:
    Database::Connection& m_db;        // +0
    // +4: the stored results, keyed by SQL (not modelled yet)
};

}  // namespace Database
