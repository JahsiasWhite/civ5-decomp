#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/ResultsCache.h"

namespace Database {

Connection& ResultsCache::Connection() {
    return m_db;
}

}  // namespace Database
