// c5d-model: Gemini 4 Hydrogen
extern void* g_table_00ca18b0[4];

// src: GUESS (confidence: high) [0x00906180]
void* __stdcall Lookup_00906180(unsigned int idx) {
    if (idx >= 4) {
        return 0;
    }
    return g_table_00ca18b0[idx];
}
