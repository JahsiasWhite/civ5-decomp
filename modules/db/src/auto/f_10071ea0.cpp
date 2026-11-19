#include <cstring>

// src: GUESS (confidence: low) [0x10001b20]
int FormatBuf_10001b20(char* buf, const char* fmt, ...);

// src: GUESS (confidence: low)
struct XMLSerializer_10071ea0
{
    char m_szCurrentFileName[256];
    char m_szErrorMessage[512];

    // src: GUESS (confidence: high) [0x10071ea0]
    void SetError(const char* szError);
};

void XMLSerializer_10071ea0::SetError(const char* szError)
{
    if (szError)
    {
        FormatBuf_10001b20(m_szErrorMessage, "Database::XMLSerializer (%s): %s", m_szCurrentFileName, szError);
    }
    else
    {
        strncpy_s(m_szErrorMessage, 512, "No Error", (size_t)-1);
    }
}
