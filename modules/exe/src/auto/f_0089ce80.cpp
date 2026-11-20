#include <string.h>

// src: GUESS (confidence: low) [0x0089ce80]
struct Unk_0089ce80
{
    int m_count;  // +0x00
    void* m_buf;  // +0x04
};

// src: GUESS (confidence: high) [0x0089ce80]
void Clear_0089ce80(Unk_0089ce80* p)
{
    if (p && p->m_count > 0)
    {
        memset(p->m_buf, 0, p->m_count * 4);
        p->m_count = 0;
    }
}
