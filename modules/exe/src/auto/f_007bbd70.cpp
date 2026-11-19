// Copies the pixels (width * height dwords) into the object's inline buffer,
// marks the format as 3, and returns the external buffer pointer.

#include <string.h>

// src: GUESS (confidence: low) [0x00a84c80]
class PixelBlock_005a9be0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    // src: GUESS (confidence: low) [0x005a9be0]
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
    // src: GUESS (confidence: low)
    int m_format;
    // src: GUESS (confidence: low)
    char m_data[4];
};

char* PixelBlock_005a9be0::Upload()
{
    m_format = 3;
    memcpy(m_data, m_pixels, m_height * m_width * 4);
    return m_buffer;
}
