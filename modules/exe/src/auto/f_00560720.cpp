
#pragma pack(push, 1)
struct Item_00490e80 {
    char pad[0x40];
    int f40;
    int f44;
    bool f48;
    char pad2[0x50 - 0x49];
};
#pragma pack(pop)

struct Class_00490e80 {
    char pad[0x40c2c];
    Item_00490e80* items;
    unsigned int count;

    int GetF44(unsigned int idx);
    int GetF40(unsigned int idx);
    bool GetF48(unsigned int idx);
};

bool Class_00490e80::GetF48(unsigned int idx) {
    if (idx >= this->count) {
        return false;
    }
    return this->items[idx].f48;
}
