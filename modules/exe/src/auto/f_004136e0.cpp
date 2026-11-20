// c5d-cflags: -/D_HAS_EXCEPTIONS=0 +/Oy-
#include <typeinfo.h>

// src: GUESS (confidence: low)
struct Interface_004136e0
{
    int m_f00;
};

// src: GUESS (confidence: low) [0x004136e0]
struct Unk_004136e0
{
    char m_pad00[0x14];  // +0x00
    int m_f14;           // +0x14

    // src: GUESS (confidence: high) [0x004136e0]
    void* QueryInterface_004136e0(const type_info& ti);
};

// src: GUESS (confidence: high) [0x004136e0]
void* Unk_004136e0::QueryInterface_004136e0(const type_info& ti)
{
    if (ti == typeid(Interface_004136e0))
        return &m_f14;
    return 0;
}
