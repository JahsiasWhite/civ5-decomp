// c5d-cflags: -/O2 -/Ob1 +/Od
// src: GUESS (confidence: low) [0x00809160]
struct StreamBuf {
    unsigned char pad[0x100];
    int advance;
    int pad104;
    int flags;
};

int __cdecl AdvanceStreamBuf(StreamBuf** ppBuf) {
    int a2 = 0;
    int a3 = 0;
    StreamBuf* a1 = *ppBuf;
    a2 = a1->flags & 0x100;
    a3 += a1->advance;
    a1 = (StreamBuf*)((char*)a1 + a1->advance);
    if (a2 == 0) {
        *ppBuf = a1;
        return 0;
    } else {
        return -1;
    }
}
