// src: GUESS (confidence: low) [0x00833590]
#include <algorithm>

struct Item36 {
    int data[9];
};

void __cdecl SwapItem36(Item36* a, Item36* b) {
    if (a != b) {
        Item36 tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
