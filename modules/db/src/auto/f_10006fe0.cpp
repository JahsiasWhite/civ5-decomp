// c5d-cflags: -/EHsc +/GS-
#include "sqlite3_api.h"

// src: GUESS (confidence: low) [0x10001b20]
int FormatBuf_10001b20(char* buf, const char* fmt, ...);

namespace Database {

// src: GUESS (confidence: low)
struct Connection_10006fe0
{
    // src: EXE [0x100013b0]
    const char* ErrorMessage() const;
    // src: EXE [0x100028a0]
    void LogMessage(const char* szMessage) const;
    // src: EXE [0x100028e0]
    void LogError(const char* szError) const;
};

// src: GUESS (confidence: low)
struct Results_10006fe0
{
    void* m_vftable;
    const Connection_10006fe0* m_conn;
    sqlite3_stmt* m_stmt;

    // src: GUESS (confidence: high) [0x10006fe0]
    bool Step();
};

bool Results_10006fe0::Step()
{
    const int SQLITE_ROW = 100;
    const int SQLITE_DONE = 101;
    int rc = sqlite3_step(m_stmt);
    if (rc != SQLITE_ROW && rc != SQLITE_DONE)
    {
        if (m_stmt && m_conn)
        {
            m_conn->LogError(m_conn->ErrorMessage());
            char buf[512];
            FormatBuf_10001b20(buf, "While executing - '%s'", sqlite3_sql(m_stmt));
            m_conn->LogMessage(buf);
        }
    }
    return rc == SQLITE_ROW;
}

}
