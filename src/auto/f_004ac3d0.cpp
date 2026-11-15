// c5d-model: claude-opus-5-5
// 0x004ac3d0: returns the address of a 0x6c-offset field inside the
// currently selected 128-byte entry of an owner's entry array.

struct Entry004ac3d0 {
    char pad[0x6c];
    int field6c;
    char pad2[0x80 - 0x70];
};

struct Owner004ac3d0 {
    char pad[0x5c];
    Entry004ac3d0* entries;  // 0x5c
    int unk60;
    int current;             // 0x64
};

int* __stdcall GetCurrentEntryField6c(Owner004ac3d0* owner)
{
    return &owner->entries[owner->current].field6c;
}
