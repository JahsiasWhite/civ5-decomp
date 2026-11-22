// src: GUESS (confidence: low)
struct BInfo {
    int f0;
    int flags;
    int f8;
    int f12;
    int f16;
    int offset;
};

// src: GUESS (confidence: low)
struct BObj {
    int pad[4];
    BInfo* info;
};

// src: GUESS (confidence: low)
struct Target8cd {
    int a;
    int b;
    int c;
};

// src: GUESS (confidence: medium)
void __cdecl f_008cd1a0(int* a, BObj* b) {
    if (!a) return;
    int base = *a;
    if (!base) return;
    BInfo* info = b->info;
    if (!info) return;
    if (!(info->flags & 2)) return;
    Target8cd* t = reinterpret_cast<Target8cd*>(info->offset + base);
    if (!t) return;
    t->a = 0;
    t->b = 0;
    t->c = 1;
}
