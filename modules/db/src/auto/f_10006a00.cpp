#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

int Results::ColumnCount() const {
    return m_Command.stmt ? sqlite3_column_count(m_Command.stmt) : 0;
}

}  // namespace Database
