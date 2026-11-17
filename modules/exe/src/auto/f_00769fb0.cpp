// c5d-model: Gemini 4 Hydrogen
extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* Addend);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* Addend);
}

// src: EXE [0x02de044c]
extern volatile long g_value_02de044c;

// src: GUESS (confidence: high) [0x00769fb0]
void UpdateRef_00769fb0(bool inc) {
    if (inc) {
        InterlockedIncrement(&g_value_02de044c);
    } else {
        InterlockedDecrement(&g_value_02de044c);
    }
}
