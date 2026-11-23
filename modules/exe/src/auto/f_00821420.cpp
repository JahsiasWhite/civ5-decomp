// src: GUESS (confidence: high)
struct Entry821420 {
    int a;
    int b;
    int c;
    int d;
};

// src: EXE [0x05c54d40]
extern Entry821420 g_entries821420[];

int __stdcall get_entry_821420(int idx, int* out_pair) {
    if (out_pair != 0) {
        out_pair[0] = g_entries821420[idx].a;
        out_pair[1] = g_entries821420[idx].b;
    }
    return g_entries821420[idx].c;
}
