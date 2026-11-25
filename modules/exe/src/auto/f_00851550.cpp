// src: GUESS (confidence: low) [0x00851550]
#include <vector>

struct InnerVecHolder {
    unsigned char pad0[0x40];
    std::vector<void*> items;
};

struct OuterVecHolder {
    unsigned char pad0[0x13a4];
    std::vector<InnerVecHolder*> holders;

    bool __thiscall ContainsPtr(void* ptr) const;
};

bool __thiscall OuterVecHolder::ContainsPtr(void* ptr) const {
    if (ptr) {
        size_t n = holders.size();
        for (size_t i = 0; i < n; ++i) {
            const std::vector<void*>& items = holders[i]->items;
            size_t m = items.size();
            for (size_t j = 0; j < m; ++j) {
                if (items[j] == ptr) {
                    return true;
                }
            }
        }
    }
    return false;
}
