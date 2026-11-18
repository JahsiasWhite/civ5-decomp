// Copies the pixels (width * height dwords) into the locked buffer, just past
// its 4-byte header, and returns the buffer.

#include <string.h>

// src: GUESS (confidence: low) [0x00a840c0]
class PixelBlock_005996b0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    // src: GUESS (confidence: low) [0x005996b0]
    virtual char* Upload();

    // src: GUESS (confidence: low)
    char* m_buffer;
    // src: GUESS (confidence: low)
    int m_width;
    // src: GUESS (confidence: low)
    int m_height;
    char m_pad10[0x10];
    // src: GUESS (confidence: low)
    const void* m_pixels;
};

char* PixelBlock_005996b0::Upload()
{
    if (m_buffer)
        memcpy(m_buffer + 4, m_pixels, m_height * m_width * 4);
    return m_buffer;
}
