#include <vector>

// src: EXE [0x00939e3c]
extern "C" __declspec(dllimport) void* __cdecl SteamUserStats();

// src: GUESS (confidence: low)
struct StatItem_004a1250 {
    int f0;
    bool f4;
    char pad5[3];
};

// src: GUESS (confidence: low)
struct Class_004a1250 {
    char pad0[0x3c];
    std::vector<StatItem_004a1250> items;
    char pad4c[0x12];
    bool ready;
    bool fn_004a1250(int index);
};

// src: GUESS (confidence: low)
bool Class_004a1250::fn_004a1250(int index) {
    if (!SteamUserStats() || !ready) {
        return false;
    }
    if (index < 0 || (unsigned int)index >= items.size()) {
        return false;
    }
    return items[index].f4;
}
