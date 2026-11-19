// src: GUESS (confidence: low) [0x0090e680]
struct SubItem_0090e680 {
    int f0;
    int f4;
};

// src: GUESS (confidence: low) [0x0090e680]
struct Class_0090e680 {
    char pad[4];
    int mode;
    char pad2[0x18 - 8];
    char flags;
    char pad3[0x28 - 0x19];
    char f28;
    char pad4[0x34 - 0x29];
    int idx;
    char pad5[0x4c - 0x38];
    SubItem_0090e680* items;

    bool Check();
};

bool Class_0090e680::Check() {
    if (this->f28 == 0) {
        char f = this->flags;
        if ((f & 1) != 0) {
            if ((f & 0x10) != 0 && (f & 0x20) != 0) {
                return true;
            }
            if ((f & 2) != 0) {
                if (this->mode == 2 || this->mode == 3) {
                    return true;
                }
                if (this->items != 0 && this->items[this->idx].f4 != 0) {
                    return true;
                }
            }
        }
    }
    return false;
}
