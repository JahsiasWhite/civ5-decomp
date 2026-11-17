#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/XMLSerializer.h"

namespace Database {

const char* XMLSerializer::ErrorMessage() const {
    return m_szErrorMessage;
}

bool XMLSerializer::UseTransactions() const {
    return m_bUseTransactions;
}

void XMLSerializer::UseTransactions(bool bUse) {
    m_bUseTransactions = bUse;
}

}  // namespace Database
