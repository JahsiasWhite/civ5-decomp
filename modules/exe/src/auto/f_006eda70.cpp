// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00da1d00]
extern int g_count_00da1d00;
// src: GUESS (confidence: high) [0x004cf810]
void FuncA_004cf810();
// src: GUESS (confidence: high) [0x00519eb0]
void FuncB_00519eb0();
// src: GUESS (confidence: high) [0x008e2cd0]
void RegisterPair_008e2cd0(void (*a)(), void (*b)());

// src: GUESS (confidence: high) [0x006eda70]
void InitPair_006eda70() {
    if (++g_count_00da1d00 != 0) {
        RegisterPair_008e2cd0(&FuncA_004cf810, &FuncB_00519eb0);
    }
}
