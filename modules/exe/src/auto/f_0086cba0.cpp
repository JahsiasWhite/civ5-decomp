#include <vector>

// src: GUESS (confidence: low)
struct Elem_0086cba0 {
    char pad[0x60];
};

// src: GUESS (confidence: low)
struct Struct_0086cba0 {
    char pad0[0x3fc0];
    std::vector<Elem_0086cba0> items;
    Elem_0086cba0* fn_0086cba0(unsigned int index);
};

// src: GUESS (confidence: low)
Elem_0086cba0* Struct_0086cba0::fn_0086cba0(unsigned int index) {
    if (index < items.size()) {
        return &items[index];
    }
    return 0;
}
