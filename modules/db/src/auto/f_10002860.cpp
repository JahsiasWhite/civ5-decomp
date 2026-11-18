#include "Database/Connection.h"

namespace Database {

static inline void ClearLogger_10002860(IDatabaseLogger*& slot) {
    if (slot != 0) {
        delete slot;
    }
    slot = 0;
}

void Connection::SetLogger(IDatabaseLogger* pLogger) {
    ClearLogger_10002860(m_pLogger);
    if (pLogger != m_pLogger && m_pLogger != 0) {
        delete m_pLogger;
    }
    m_pLogger = pLogger;
}

}  // namespace Database
