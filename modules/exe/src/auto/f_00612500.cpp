// src: GUESS (confidence: low) [0x00612500]
struct Node48_00612500 {
    unsigned int m_next;
    char pad[0x2c];
};

// src: GUESS (confidence: low) [0x00612500]
struct VecWrap_00612500 {
    char pad[8];
    Node48_00612500* m_data;
};

// src: GUESS (confidence: low) [0x00612500]
struct Cont_00612500 {
    VecWrap_00612500* m_vec;
    char pad[4];
    unsigned int m_head;
};

// src: GUESS (confidence: low) [0x00612500]
struct Iter_00612500 {
    Cont_00612500* m_cont;
    unsigned int m_idx;
};

// src: GUESS (confidence: low) [0x00612500]
void __cdecl Advance_00612500(Iter_00612500* it, unsigned int n) {
    if (n > 0) {
        Cont_00612500* cont = it->m_cont;
        do {
            unsigned int idx = it->m_idx;
            if (idx == 0xfffffff) {
                idx = cont->m_head;
            } else {
                idx = cont->m_vec->m_data[idx].m_next;
            }
            it->m_idx = idx;
            --n;
        } while (n != 0);
    }
}
