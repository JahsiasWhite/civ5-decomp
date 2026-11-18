#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Reset() {
    if (m_Command.stmt != 0 && sqlite3_clear_bindings(m_Command.stmt) == 0) {
        return sqlite3_reset(m_Command.stmt) == 0;
    }
    return false;
}

}  // namespace Database
