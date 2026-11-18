#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::TryReset() {
    if (m_Command.stmt != 0) {
        sqlite3_clear_bindings(m_Command.stmt);
        return sqlite3_reset(m_Command.stmt) == 0;
    }
    return false;
}

}  // namespace Database
