#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

const char* Connection::ErrorMessage() const {
    return m_pDb ? sqlite3_errmsg(m_pDb) : 0;
}

}  // namespace Database
