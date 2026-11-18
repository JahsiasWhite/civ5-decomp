#include <new>

// src: GUESS (confidence: low)
class ArenaPool_10008660 {
public:
    // src: GUESS 0x10008660 (confidence: medium)
    void Reset();

    // src: GUESS (confidence: low)
    struct Chunk {
        Chunk* next;
        char* cursor;
    };

    // src: GUESS (confidence: low)
    Chunk* m_head;             // +0x00
    unsigned int m_remaining;  // +0x04
    Chunk m_base;              // +0x08
    char m_buf[0x10000];       // +0x10..+0x1000f
    int m_pad;                 // +0x10010
    void (*m_pFree)(void*);    // +0x10014
};

void ArenaPool_10008660::Reset() {
    while (m_head != &m_base) {
        Chunk* next = m_head->next;
        if (m_pFree != 0) {
            m_pFree(m_head);
        } else {
            operator delete[](m_head);
        }
        m_head = next;
    }
    m_head->cursor = (char*)(m_head + 1);
    m_remaining = 0x10000;
}
