// c5d-cflags: +/Oy-
// src: GUESS (confidence: medium) [0x0056b480]
void __stdcall ArrayForEach_0056b480(char* ptr, int stride, int count, void (__thiscall* fn)(void*)) {
    if (--count >= 0) {
        do {
            fn(ptr);
            ptr += stride;
        } while (--count >= 0);
    }
}
