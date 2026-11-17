// c5d-model: Gemini 4 Hydrogen
extern void** g_arr_02d6fbb4;
extern unsigned int g_count_02d6fbb8;

// src: GUESS (confidence: high) [0x004f8ce0]
void* __cdecl GetItem_004f8ce0(unsigned int idx) {
    if (idx < g_count_02d6fbb8) {
        return g_arr_02d6fbb4[idx];
    }
    return 0;
}
