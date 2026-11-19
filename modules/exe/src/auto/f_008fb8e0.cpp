// src: GUESS (confidence: low) [0x00998520]
struct Class_00998520 {
    unsigned int Swap();
};

unsigned int Class_00998520::Swap() {
    unsigned int v = (unsigned int)this;
    unsigned int a = ((v & 0xff00) | (v << 16));
    unsigned int b = ((v & 0xff0000) | (v >> 16));
    return (a << 8) | (b >> 8);
}
