// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) void __stdcall AIL_sample_volume_pan(void* s, int volume, int pan);

// src: LIB [0x00923280]
void __cdecl AIL_SampleVolumePanThunk_00923280(void* s, int volume, int pan) {
    AIL_sample_volume_pan(s, volume, pan);
}
