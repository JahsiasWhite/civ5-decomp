#include "Database/Connection.h"
#include "sqlite3_api.h"

// src: GUESS (confidence: low)
class ConnectionExt_10002900 {
public:
    // src: GUESS 0x10002900 (confidence: medium)
    bool CheckCode(int code);

    // src: GUESS (confidence: high)
    sqlite3* m_pDb;             // +0x00
    char m_pad04[0x74];         // +0x04
    // src: GUESS (confidence: high)
    Database::IDatabaseLogger* m_pLogger; // +0x78
};

bool ConnectionExt_10002900::CheckCode(int code) {
    if (code == 0) {
        return true;
    }
    const char* msg = m_pDb ? sqlite3_errmsg(m_pDb) : 0;
    Database::IDatabaseLogger* pLogger = m_pLogger;
    if (pLogger != 0) {
        pLogger->LogMessage(msg, 2);
    }
    return false;
}
