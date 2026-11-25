// src: GUESS (confidence: low) [0x00508820]
struct GridBounds {
    int minX;
    int minY;
    int maxX;
    int maxY;
    int width;
    int height;
    int pad18;
    unsigned char value;
    unsigned char pad1D[3];
    struct Cell {
        int a;
        int b;
        unsigned char val;
        unsigned char pad[3];
    } *cells;

    void __thiscall SetWrappedCell(int x, int y);
};

void __thiscall GridBounds::SetWrappedCell(int x, int y) {
    int wx = (width * 100 + x) % width;
    int wy = (height * 100 + y) % height;
    if (wx >= minX && wx < maxX && wy >= minY && wy < maxY) {
        cells[((wy % 64) << 6) + (wx % 64)].val = value;
    }
}
