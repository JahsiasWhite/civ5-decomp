// src: GUESS (confidence: medium) [0x0075aa60]
void __stdcall ArrayCopyCtor_0075aa60(char* dst, const char* src, int stride, int count, void (__thiscall* ctor)(void*, const void*)) {
    if (--count >= 0) {
        do {
            ctor(dst, src);
            dst += stride;
            src += stride;
        } while (--count >= 0);
    }
}
