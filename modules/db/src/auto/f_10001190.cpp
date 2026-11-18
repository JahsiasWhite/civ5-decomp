#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Connection.h"
#include "sqlite3_api.h"

namespace Database {

int Connection::TotalChanges() const {
    return m_pDb ? sqlite3_total_changes(m_pDb) : 0;
}

}  // namespace Database
