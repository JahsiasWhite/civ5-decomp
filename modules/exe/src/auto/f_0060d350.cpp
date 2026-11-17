// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x02e49edc]
extern int g_state_02e49edc;
// src: GUESS (confidence: high) [0x00d90ee8]
extern char g_flag_00d90ee8;

// src: GUESS (confidence: high) [0x0060d350]
int CheckReady_0060d350() {
    if (g_state_02e49edc >= 9 && g_flag_00d90ee8 != 0) {
        return 1;
    }
    return 0;
}
