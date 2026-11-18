// src: EXE [0x10008b20]
#include <new>

extern "C" void* malloc(unsigned int size);

// src: GUESS (confidence: low)
struct ArenaPool_10008b20 {
    struct Chunk {
        Chunk(Chunk* n) : next(n), cursor((char*)this + 8) {}
        Chunk* next;
        char* cursor;
    };

    void* Alloc(unsigned int size);

    Chunk* m_head;
    unsigned int m_remaining;
    Chunk m_base;
    char m_buf[0x10000];
    void* (*m_pAlloc)(unsigned int);
};

// src: GUESS (confidence: low)
void* ArenaPool_10008b20::Alloc(unsigned int size) {
    if ((unsigned int)(m_head->cursor - (char*)m_head - 8) + size > m_remaining) {
        unsigned int blockSize = (size <= 0x10000) ? 0x10000 : size;
        void* mem;
        if (m_pAlloc != 0) {
            m_remaining = blockSize;
            mem = m_pAlloc(blockSize + 8);
        } else {
            m_remaining = blockSize;
            mem = malloc(blockSize + 8);
            if (mem == 0) {
                return 0;
            }
        }
        m_head = new (mem) Chunk(m_head);
    }
    void* result = m_head->cursor;
    m_head->cursor += size;
    return result;
}
