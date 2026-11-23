// src: GUESS (confidence: low)
struct Item16 {
    int a;
    float f;
    int b;
    int key;
};

static inline bool less16(const Item16* lhs, const Item16* rhs) {
    if (lhs->key < rhs->key) return true;
    if (lhs->key > rhs->key) return false;
    return lhs->f < rhs->f;
}

static inline void swap16(Item16* x, Item16* y) {
    if (x != y) {
        Item16 t = *x;
        *x = *y;
        *y = t;
    }
}

void f_00860e20(Item16* a, Item16* b, Item16* c) {
    if (less16(b, a)) {
        swap16(b, a);
    }
    if (less16(c, b)) {
        swap16(c, b);
    }
    if (less16(b, a)) {
        swap16(b, a);
    }
}
