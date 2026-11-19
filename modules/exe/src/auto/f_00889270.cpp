// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_sample_reverb_levels(void* s, int dry, int wet);

// src: LIB [0x00923670]
void __cdecl AIL_SampleReverbLevelsThunk_00923670(void* s, int dry, int wet) {
    AIL_sample_reverb_levels(s, dry, wet);
}
