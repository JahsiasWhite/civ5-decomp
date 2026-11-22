// src: GUESS (confidence: low) [0x008d8840]
struct Inner_008d8840 {
    char pad0[0xc]; // src: GUESS (confidence: low) [0x008d8840]
    void (__cdecl *m_fn)(void*, void*); // src: GUESS (confidence: low) [0x008d8840]
};

struct Auto_008d8840 {
    char pad0[0x14]; // src: GUESS (confidence: low) [0x008d8840]
    Inner_008d8840* m_14; // src: GUESS (confidence: low) [0x008d8840]
    void* m_18; // src: GUESS (confidence: low) [0x008d8840]
};

void f_008d8840(Auto_008d8840* p, void* arg) {
    if (arg) {
        void (__cdecl *fn)(void*, void*) = p->m_14->m_fn;
        if (fn) {
            fn(p->m_18, arg);
        }
    }
}
