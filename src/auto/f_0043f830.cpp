// c5d-model: Gemini 3.8 Flash

#include <string.h>

struct DataBlock_0043f830 {
    char m_bytes[0x213 * 4];
};

// src: GUESS (confidence: high) [0x0043f830]
struct Host_0043f830 {
    char m_pad[0x24];
    DataBlock_0043f830 m_data;
    void CopyData(const DataBlock_0043f830* src);
};

// src: GUESS (confidence: high) [0x0043f830]
void Host_0043f830::CopyData(const DataBlock_0043f830* src)
{
    m_data = *src;
}
