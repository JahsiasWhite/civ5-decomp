#include <vector>

// src: GUESS (confidence: low)
struct Elem_006440f0 {
    char pad[0x5c];
};

// src: GUESS (confidence: low)
struct Struct_006440f0 {
    char pad0[0x60];
    std::vector<Elem_006440f0> items;
    Elem_006440f0* fn_006440f0(int index);
};

// src: GUESS (confidence: low)
Elem_006440f0* Struct_006440f0::fn_006440f0(int index) {
    if (index >= 0 && index < (int)items.size()) {
        return &items[index];
    }
    return 0;
}
