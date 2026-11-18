#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Results.h"

namespace Database {

void Results::SingleQuery(bool bSingleQuery) {
    m_bSingleQuery = bSingleQuery;
}

}  // namespace Database
