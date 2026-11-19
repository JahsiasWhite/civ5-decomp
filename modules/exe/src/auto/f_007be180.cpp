// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __cdecl sprintf_s(char* buf, unsigned int sz, const char* fmt, ...);

// src: EXE [0x00a8d924]
extern const char g_str_NetInitPlayers_00a8d924[];

// src: GUESS (confidence: high) [0x005e91a0]
int __stdcall FormatNetInit_005e91a0(char* buf, unsigned int sz) {
    return sprintf_s(buf, sz, g_str_NetInitPlayers_00a8d924);
}
