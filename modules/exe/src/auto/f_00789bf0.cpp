// c5d-cflags: -/arch:SSE2
// Signed area of the triangle (a, b, c).

// src: GUESS (confidence: low)
struct Vec2_00789bf0
{
    float x;
    float y;
};

// src: GUESS (confidence: low) [0x00789bf0]
float TriangleArea_00789bf0(const Vec2_00789bf0* a, const Vec2_00789bf0* b, const Vec2_00789bf0* c)
{
    float ay = a->y;
    float ax = a->x;
    return ((c->y - ay) * (b->x - ax) - (b->y - ay) * (c->x - ax)) * 0.5f;
}
