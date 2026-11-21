// src: GUESS (confidence: high) [0x00821420]
struct Entry821420 {
    int a;
    int b;
    int c;
    int d;
};

// src: GUESS (confidence: high) [0x05c54d40]
extern Entry821420 g_arr821420[];

// src: GUESS (confidence: high) [0x00821420]
int __stdcall f_00821420(int idx, Entry821420* out) {
    if (out) {
        out->a = g_arr821420[idx].a;
        out->b = g_arr821420[idx].b;
    }
    return g_arr821420[idx].c;
}
