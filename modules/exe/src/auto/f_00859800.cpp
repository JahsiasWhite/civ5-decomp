#include <vector>

// src: GUESS (confidence: low)
struct Item_00859800 {
    int f0;
    int id;
};

// src: GUESS (confidence: low)
struct Struct_00859800 {
    int f0;
    std::vector<Item_00859800*> items;
    Item_00859800* fn_00859800(int id);
};

// src: GUESS (confidence: low)
Item_00859800* Struct_00859800::fn_00859800(int id) {
    for (unsigned int i = 0; i < items.size(); ++i) {
        Item_00859800* p = items[i];
        if (p && p->id == id) {
            return p;
        }
    }
    return 0;
}
