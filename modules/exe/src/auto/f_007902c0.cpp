// src: GUESS (confidence: low)
struct Item8_007902c0 {
    int a;
    int b;
};

// src: GUESS (confidence: low)
struct Iter8_007902c0 {
    Item8_007902c0* ptr;
    Iter8_007902c0(Item8_007902c0* p) : ptr(p) {}
};

// src: GUESS (confidence: low)
class Vec8_007902c0 {
public:
    // src: GUESS (confidence: low) [0x007902c0]
    Iter8_007902c0 Erase(Iter8_007902c0 first, Iter8_007902c0 last);

private:
    void* m_pad;
    Item8_007902c0* m_first;
    Item8_007902c0* m_last;
    Item8_007902c0* m_end;
};

Iter8_007902c0 Vec8_007902c0::Erase(Iter8_007902c0 first, Iter8_007902c0 last)
{
    Iter8_007902c0 ret = first;
    Item8_007902c0* dst = first.ptr;
    Item8_007902c0* src = last.ptr;
    if (dst != src) {
        Item8_007902c0* end = m_last;
        if (src != end) {
            do {
                *dst = *src;
                ++src;
                ++dst;
            } while (src != end);
        }
        m_last = dst;
    }
    return ret;
}
