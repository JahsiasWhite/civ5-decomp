// Function: 0x0051b290
// c5d-cflags: -/arch:SSE2 +/arch:SSE
#include <math.h>

#define SEG_MAX(a, b) ((a) > (b) ? (a) : (b))
#define SEG_MIN(a, b) ((a) < (b) ? (a) : (b))

struct Seg2D { // src: GUESS (confidence: high)
    float x0; // src: GUESS (confidence: high)
    float y0; // src: GUESS (confidence: high)
    float x1; // src: GUESS (confidence: high)
    float y1; // src: GUESS (confidence: high)
};

struct SegVec2 { // src: GUESS (confidence: high)
    float x; // src: GUESS (confidence: high)
    float y; // src: GUESS (confidence: high)
};

bool IntersectSegments2D(const Seg2D* pA, const Seg2D* pB, SegVec2* pOut, float fEps) { // src: GUESS (confidence: high) [0x0051b290]
    float a1 = pA->y1 - pA->y0;
    float b1 = pA->x0 - pA->x1;
    float c1 = pA->x0 * a1 + pA->y0 * b1;

    float a2 = pB->y1 - pB->y0;
    float b2 = pB->x0 - pB->x1;
    float c2 = pB->x0 * a2 + pB->y0 * b2;

    float det = b2 * a1 - a2 * b1;
    if (fabs((double)det) < fEps) {
        return false;
    }

    float invDet = 1.0f / det;
    pOut->x = (b2 * c1 - b1 * c2) * invDet;
    pOut->y = (a1 * c2 - a2 * c1) * invDet;

    if (pOut->x > SEG_MIN(SEG_MAX(pA->x0, pA->x1), SEG_MAX(pB->x0, pB->x1)) + fEps) {
        return false;
    }
    if (pOut->x < SEG_MAX(SEG_MIN(pA->x0, pA->x1), SEG_MIN(pB->x0, pB->x1)) - fEps) {
        return false;
    }
    if (pOut->y > SEG_MIN(SEG_MAX(pA->y0, pA->y1), SEG_MAX(pB->y0, pB->y1)) + fEps) {
        return false;
    }
    if (pOut->y < SEG_MAX(SEG_MIN(pA->y0, pA->y1), SEG_MIN(pB->y0, pB->y1)) - fEps) {
        return false;
    }

    return true;
}
