// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
#include <algorithm>

struct F0054d5c0Item {
    int a;
    int b;
    int c;
};

struct F0054d5c0Pred {
    int val;
    bool operator()(const F0054d5c0Item& item) const {
        return !(item.a == val && item.b == val);
    }
};

void __cdecl f_0054d5c0(F0054d5c0Item* first, F0054d5c0Item* last, int val) {
    F0054d5c0Pred pred;
    pred.val = val;
    std::partition(first, last, pred);
}
