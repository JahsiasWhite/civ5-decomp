// src: GUESS (confidence: high) [0x1000bc80]
#include <string>

struct Entry60 {
    std::string a;
    std::string b;
    int pad;
};

struct RawVec60 {
    void* alloc;
    Entry60* first;
    Entry60* last;
    Entry60* end;
};

void __stdcall tidy_entry60_vec(RawVec60* v) {
    Entry60* first = v->first;
    if (first != 0) {
        Entry60* last = v->last;
        for (Entry60* p = first; p != last; ++p) {
            p->b.~basic_string();
            p->a.~basic_string();
        }
        ::operator delete(v->first);
    }
    v->first = 0;
    v->last = 0;
    v->end = 0;
}
