// src: GUESS (confidence: low) [0x008f8a10]
struct Class_008f8a10 {
    char pad[0xb8];
    unsigned int a;
    unsigned int b;

    int Check();
};

int Class_008f8a10::Check() {
    if ((this->a + 3) < 0xffff && (this->b + 3) < 0x17ffe) {
        return 1;
    }
    return 0;
}
