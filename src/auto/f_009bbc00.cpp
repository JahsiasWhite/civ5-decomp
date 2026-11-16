// c5d-model: Gemini 4 Hydrogen
struct Item64_009bbc00 {
    char data[0x40];
};

struct Table_009bbc00 {
    int count;
    Item64_009bbc00* items;
};

// src: LIB [0x009bbc00]
Item64_009bbc00* __cdecl Lookup_009bbc00(const Table_009bbc00* host, int idx) {
    if (idx >= host->count) {
        return 0;
    }
    return &host->items[idx];
}
