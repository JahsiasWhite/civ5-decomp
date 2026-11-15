// Swaps two 2-component float vectors (std::swap-style helper).

struct Vec2f
{
    float x;
    float y;

    Vec2f() {}
    Vec2f(const Vec2f& o) : x(o.x), y(o.y) {}
};

void SwapVec2f(Vec2f* a, Vec2f* b)
{
    if (a != b)
    {
        Vec2f tmp(*a);
        *a = *b;
        *b = tmp;
    }
}
