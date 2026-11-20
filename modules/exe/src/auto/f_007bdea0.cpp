// c5d-cflags: -/Ob1 +/Ob0
#include <stdio.h>
#include <string>

// src: GUESS (confidence: low) [0x007bdea0]
struct NetVersionNack_007bdea0
{
    char m_pad00[0x30];           // +0x00
    int m_eVersionType;           // +0x30
    int m_iIntValue;              // +0x34
    std::string m_szStringValue;  // +0x38

    // src: GUESS (confidence: high) [0x007bdea0]
    int FormatInfo_007bdea0(char* dst, unsigned int dstSize);
};

// src: GUESS (confidence: high) [0x007bdea0]
int NetVersionNack_007bdea0::FormatInfo_007bdea0(char* dst, unsigned int dstSize)
{
    return sprintf_s(
        dst,
        dstSize,
        "NetVersionNack : m_eVersionType=%d, m_iIntValue=%d, m_szStringValue=\"%s\"",
        m_eVersionType,
        m_iIntValue,
        m_szStringValue.c_str());
}
