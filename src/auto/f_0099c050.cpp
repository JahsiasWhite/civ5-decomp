// c5d-model: Gemini 4 Hydrogen
// src: LIB [0x0099c050]
int __fastcall SafeStrLen_0099c050(const char* s) {
    int len = 0;
    if (s && *s) {
        do {
            ++s;
            ++len;
        } while (*s);
    }
    return len;
}
