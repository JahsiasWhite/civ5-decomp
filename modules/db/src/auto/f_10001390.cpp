#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

int Connection::ErrorCode() const {
    return m_pDb ? sqlite3_errcode(m_pDb) : -1;
}

}  // namespace Database
