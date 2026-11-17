// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00969d50]
int __cdecl Exchange_00969d50(const int* offset_ptr, int new_val, const int* base_ptr) {
    int* p = (int*)(*(const char* const*)(base_ptr + 1) + *offset_ptr);
    int old = *p;
    *p = new_val;
    return old;
}
