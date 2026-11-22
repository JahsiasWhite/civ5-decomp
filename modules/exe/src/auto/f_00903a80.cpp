// src: GUESS (confidence: low) [0x00903a80]
extern const char g_str_00a047d4[]; // src: GUESS (confidence: low) [0x00a047d4]
extern void (__cdecl *g_free_00b44854)(const char*, int, void*); // src: GUESS (confidence: low) [0x00b44854]

struct Node_00903a80 {
    Node_00903a80* m_next; // src: GUESS (confidence: low) [0x00903a80]
};

void f_00903a80(Node_00903a80* p) {
    if (p) {
        f_00903a80(p->m_next);
        g_free_00b44854(g_str_00a047d4, 0x3d, p);
    }
}
