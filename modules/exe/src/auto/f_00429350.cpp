#include <stdio.h>

// src: GUESS (confidence: low)
struct Inner_00429350
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    // src: GUESS (confidence: low)
    virtual unsigned int GetSize12();
};

// src: GUESS (confidence: low) [0x00429350]
struct NetMessageBundle_00429350
{
    char m_pad00[0x30];           // +0x00
    unsigned int m_uiMessageCount;// +0x30
    Inner_00429350 m_inner34;     // +0x34

    // src: GUESS (confidence: high) [0x00429350]
    int FormatInfo_00429350(char* dst, int unused);
};

// src: GUESS (confidence: high) [0x00429350]
int NetMessageBundle_00429350::FormatInfo_00429350(char* dst, int unused)
{
    return sprintf(dst, "NetMessageBundle : m_uiMessageCount=%u, size=%u", m_uiMessageCount, m_inner34.GetSize12());
}
