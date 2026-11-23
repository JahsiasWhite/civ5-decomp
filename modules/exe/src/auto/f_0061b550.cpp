// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Item12_0061b550 {
    int a;
    int b;
    int c;
};

// src: GUESS (confidence: low)
struct Iter12_0061b550 {
    Item12_0061b550* ptr;
    Iter12_0061b550(Item12_0061b550* p) : ptr(p) {}
};

// src: GUESS (confidence: low)
class Vec12_0061b550 {
public:
    // src: GUESS (confidence: low) [0x0061b550]
    Iter12_0061b550 Erase(Iter12_0061b550 pos);

private:
    void* m_pad;
    Item12_0061b550* m_first;
    Item12_0061b550* m_last;
    Item12_0061b550* m_end;
};

Iter12_0061b550 Vec12_0061b550::Erase(Iter12_0061b550 pos)
{
    Item12_0061b550* dst = pos.ptr;
    Item12_0061b550* last = m_last;
    Item12_0061b550* src = dst + 1;
    if (src != last) {
        while (src != last) {
            *dst = *src;
            ++src;
            ++dst;
        }
    }
    --m_last;
    return pos;
}
