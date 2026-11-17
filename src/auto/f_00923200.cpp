// c5d-model: Gemini 4 Hydrogen
extern "C" {
    __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
    __declspec(dllimport) int __stdcall AIL_set_sample_playback_rate(void* sample, int rate);
}

// src: LIB [0x00923200]
int __cdecl SetStreamRate_00923200(void* stream, int rate) {
    void* sample = AIL_stream_sample_handle(stream);
    return AIL_set_sample_playback_rate(sample, rate);
}
