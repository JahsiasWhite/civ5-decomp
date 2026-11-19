// c5d-model: Gemini 4 Hydrogen
extern char g_byte_00c8eff8;
// src: GUESS (confidence: high) [0x006d4170]
char __cdecl ExchangeByte_006d4170(char val) {
    char old = g_byte_00c8eff8;
    g_byte_00c8eff8 = val;
    return old;
}
