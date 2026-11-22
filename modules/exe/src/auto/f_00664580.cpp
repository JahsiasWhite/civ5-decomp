// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Item16 {
    int a, b, c, d;
};

// src: GUESS (confidence: low)
class StreamReader {
public:
    char pad[0x10264];
    const char* end;
    const char* cur;

    // src: GUESS (confidence: medium)
    bool Read16(Item16* out);
};

bool StreamReader::Read16(Item16* out) {
    const char* p = cur;
    bool ok = false;
    if (p + sizeof(Item16) <= end) {
        *out = *reinterpret_cast<const Item16*>(p);
        ok = true;
    }
    cur += sizeof(Item16);
    return ok;
}
