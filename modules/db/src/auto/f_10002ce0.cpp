#include "Database/Connection.h"
#include "sqlite3_api.h"

// src: GUESS (confidence: low)
struct ConnectionRaw_10002ce0 {
    // src: GUESS (confidence: high)
    sqlite3* m_pDb;             // +0x00
    char m_pad04[0x74];         // +0x04
    // src: GUESS (confidence: high)
    Database::IDatabaseLogger* m_pLogger; // +0x78
};

// src: GUESS (confidence: low)
struct Command_10002ce0 {
    // src: GUESS (confidence: low)
    ConnectionRaw_10002ce0* connection;
    // src: GUESS (confidence: low)
    sqlite3_stmt* stmt;
};

// src: GUESS 0x10002ce0 (confidence: high)
void FinalizeCommand_10002ce0(Command_10002ce0* cmd) {
    if (cmd->stmt != 0) {
        if (sqlite3_finalize(cmd->stmt) != 0) {
            sqlite3* db = cmd->connection->m_pDb;
            const char* szErr = db ? sqlite3_errmsg(db) : 0;
            Database::IDatabaseLogger* pLogger = cmd->connection->m_pLogger;
            if (pLogger != 0) {
                pLogger->LogMessage(szErr, 2);
            }
        }
        cmd->stmt = 0;
    }
}
