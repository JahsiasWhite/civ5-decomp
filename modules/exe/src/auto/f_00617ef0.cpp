// src: GUESS (confidence: high)
struct Item44 {
    unsigned char pad[0x24];
    int value; // 0x24
    int tail;  // 0x28
};

struct Container617ef0 {
    Item44* items;               // 0x00
    unsigned int count;          // 0x04
    unsigned char pad[0x300];    // 0x08..0x307
    int default_val;             // 0x308
};

void __stdcall set_items_default(Container617ef0* c) {
    unsigned int i = 0;
    if (c->count > i) {
        unsigned int off = 0;
        do {
            *(int*)((char*)c->items + off + 0x24) = c->default_val;
            ++i;
            off += 0x2c;
        } while (i < c->count);
    }
}
