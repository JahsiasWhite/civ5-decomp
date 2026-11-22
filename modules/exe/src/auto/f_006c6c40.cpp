// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Item16 {
    int a, b, c, d;
};

// src: GUESS (confidence: low)
struct ListNode16 {
    ListNode16* next;
    ListNode16* prev;
    Item16 val;
};

// src: GUESS (confidence: low)
struct ListIter16 {
    const ListNode16* node;
    ListIter16& operator++() { node = node->next; return *this; }
    bool operator!=(const ListIter16& o) const { return node != o.node; }
};

// src: GUESS (confidence: medium)
Item16* __cdecl f_006c6c40(ListIter16 begin, ListIter16 end, Item16* dst) {
    for (; begin != end; ++begin, ++dst) {
        if (dst) {
            *dst = begin.node->val;
        }
    }
    return dst;
}
