// src: GUESS (confidence: low) [0x007b7220]
extern void* g_vtable_009ac718[]; // src: GUESS (confidence: low) [0x009ac718]
void __stdcall free_0088970e(void* p); // src: GUESS (confidence: low) [0x0088970e]
void __stdcall free_00889708(void* p); // src: GUESS (confidence: low) [0x00889708]

struct Auto_007b7220 {
    void* m_vptr; // src: GUESS (confidence: low) [0x007b7220]
    void* m_4; // src: GUESS (confidence: low) [0x007b7220]

    void* f_007b7220(unsigned char flags); // src: GUESS (confidence: low) [0x007b7220]
};

void* Auto_007b7220::f_007b7220(unsigned char flags) {
    m_vptr = g_vtable_009ac718;
    free_0088970e(m_4);
    if (flags & 1) {
        free_00889708(this);
    }
    return this;
}
