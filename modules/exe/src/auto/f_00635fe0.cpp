// Returns a pointer to the indexed 0x2d60-byte entry of an array embedded at
// offset 0x278 of the owning object.

struct Entry_00722720 {
    char data[0x2d60];
};

class EntryTable_00722720 {
public:
    Entry_00722720* GetEntry(int index);

    char pad[0x278];
    Entry_00722720 entries[1];
};

Entry_00722720* EntryTable_00722720::GetEntry(int index)
{
    return &entries[index];
}
