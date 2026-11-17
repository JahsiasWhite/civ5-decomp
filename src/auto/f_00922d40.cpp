// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) int __stdcall AIL_set_speaker_configuration(void* dig, void* a, void* b, float fb);

// src: GUESS (confidence: high) [0x00922d40]
bool SetSpeakers_00922d40(void* dig, float fb) {
    AIL_set_speaker_configuration(dig, 0, 0, fb);
    return true;
}
