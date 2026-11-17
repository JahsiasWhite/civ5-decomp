// c5d-model: Gemini 4 Hydrogen
struct Sub_009bbd70 {
    int f0, f4;
    void* primary;
    int fc;
    void* secondary;
};

struct Host_009bbd70 {
    char pad[0x10];
    Sub_009bbd70* sub;
};

// src: LIB [0x009bbd70]
void* __cdecl GetSubPtr_009bbd70(const Host_009bbd70* h) {
    void* res = 0;
    Sub_009bbd70* s = h->sub;
    if (s) {
        res = s->primary;
        if (!res) {
            res = s->secondary;
        }
    }
    return res;
}
