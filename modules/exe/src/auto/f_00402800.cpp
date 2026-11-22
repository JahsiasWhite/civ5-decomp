// src: GUESS (confidence: low) [0x00402800]
extern void* g_vtable_00a13e7c[]; // src: GUESS (confidence: low) [0x00a13e7c]
extern void (__cdecl *g_free_00b42424)(void*); // src: GUESS (confidence: low) [0x00b42424]

struct Auto_00402800 {
    void* m_vptr; // src: GUESS (confidence: low) [0x00402800]

    void* f_00402800(unsigned char flags); // src: GUESS (confidence: low) [0x00402800]
};

void* Auto_00402800::f_00402800(unsigned char flags) {
    m_vptr = g_vtable_00a13e7c;
    if (flags & 1) {
        g_free_00b42424(this);
    }
    return this;
}
