// src: GUESS (confidence: high) [0x1000a550]
struct Form88Virtual {
    virtual ~Form88Virtual() {}
    char pad[0x54];
};

struct RawVec88 {
    void* alloc;
    Form88Virtual* first;
    Form88Virtual* last;
    Form88Virtual* end;
};

void __stdcall tidy_form88_vec(RawVec88* v) {
    Form88Virtual* first = v->first;
    if (first != 0) {
        Form88Virtual* last = v->last;
        for (Form88Virtual* p = first; p != last; ++p) {
            p->~Form88Virtual();
        }
        ::operator delete(v->first);
    }
    v->first = 0;
    v->last = 0;
    v->end = 0;
}
