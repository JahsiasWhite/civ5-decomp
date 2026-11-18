#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"

namespace Database {

const char* Results::GetColumns() const {
    return m_szColumns ? m_szColumns : "*";
}

}  // namespace Database
