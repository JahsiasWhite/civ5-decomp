#include <windows.h>

// src: GUESS (confidence: low)
class Win7bb {
public:
    int f0;
    int f4;
    int w;
    int h;
    int f16;
    HDC hdc;

    // src: GUESS (confidence: medium)
    void PaintBlack();
};

void Win7bb::PaintBlack() {
    RECT r;
    r.left = 0;
    r.top = 0;
    r.right = w;
    r.bottom = h;
    FillRect(hdc, &r, (HBRUSH)GetStockObject(BLACK_BRUSH));
}
