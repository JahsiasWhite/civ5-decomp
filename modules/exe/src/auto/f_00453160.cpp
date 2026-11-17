// c5d-model: Gemini 3.8 Flash
struct Inner_00453160 {
    char pad[0x44];
    int value;
};

struct Outer_00453160 {
    Inner_00453160* inner;
};

// src: GUESS (confidence: high) [0x00453160]
int __stdcall GetVal_00453160(Outer_00453160* obj) {
    if (obj->inner) {
        return obj->inner->value;
    }
    return 0;
}
