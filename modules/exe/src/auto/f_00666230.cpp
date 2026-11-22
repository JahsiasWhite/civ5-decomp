// src: GUESS (confidence: low)
struct Elem8 {
    int a;
    int b;
};

// src: GUESS (confidence: low)
struct Iter8 {
    Elem8* ptr;
    Iter8(Elem8* p) : ptr(p) {}
    Iter8& operator++() { ++ptr; return *this; }
    bool operator!=(const Iter8& o) const { return ptr != o.ptr; }
};

// src: GUESS (confidence: medium)
Iter8 __cdecl f_00666230(Iter8 begin, Iter8 end, const Elem8& target) {
    for (; begin != end; ++begin) {
        if (begin.ptr->a == target.a && begin.ptr->b == target.b) {
            break;
        }
    }
    return begin;
}
