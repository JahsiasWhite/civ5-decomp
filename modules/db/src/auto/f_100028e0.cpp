#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Connection.h"

namespace Database {

void Connection::LogError(const char* szMessage) const {
    IDatabaseLogger* pLogger = m_pLogger;
    if (pLogger != 0) {
        pLogger->LogMessage(szMessage, 2);
    }
}

}  // namespace Database
