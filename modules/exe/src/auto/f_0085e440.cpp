// src: GUESS (confidence: low) [0x008f8a40]
struct Class_008f8a40 {
    char pad[0xb8];
    unsigned int a;
    unsigned int b;

    int Check();
};

int Class_008f8a40::Check() {
    if ((this->a + 4) < 0xffff && (this->b + 6) < 0x17ffe) {
        return 1;
    }
    return 0;
}
