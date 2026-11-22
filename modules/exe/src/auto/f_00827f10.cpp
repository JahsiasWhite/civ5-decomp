// src: GUESS (confidence: high) [0x00827f10]
struct Entry_00827f10 {
    int next;
    int prev;
    unsigned char pad[0xf8];
};

// src: GUESS (confidence: high) [0x00827f10]
struct Pool_00827f10 {
    int pad0;
    int pad4;
    Entry_00827f10* entries;

    void link(int idx, int nextIdx);
};

// src: GUESS (confidence: high) [0x00827f10]
void Pool_00827f10::link(int idx, int nextIdx) {
    Entry_00827f10* e = &entries[idx];
    if (nextIdx == 0xfffffff) {
        e->prev = nextIdx;
        e->next = nextIdx;
        return;
    }
    Entry_00827f10* n = &entries[nextIdx];
    int oldPrev = n->prev;
    e->next = nextIdx;
    e->prev = oldPrev;
    if (oldPrev != 0xfffffff) {
        entries[oldPrev].next = idx;
    }
    n->prev = idx;
}
