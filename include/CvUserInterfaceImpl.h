// c5d-vtable: 0x009fb858
#pragma once

// src: SDK
class CvUserInterfaceImpl
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;
    // src: GUESS (confidence: high)
    char m_pad04[0x1ba];
    // src: GUESS (confidence: medium)
    char m_flag1BE;
    // src: GUESS (confidence: high)
    char m_pad1BF[0x8d];
    // src: GUESS (confidence: medium)
    int m_field24C;
    // src: GUESS (confidence: medium)
    int m_field250;

    // src: GUESS (confidence: medium) [0x00562440]
    char GetFlag1BE() const;
    // src: GUESS (confidence: medium) [0x00536b90]
    int GetField24C() const;
    // src: GUESS (confidence: medium) [0x0068d590]
    int GetField250() const;
};
