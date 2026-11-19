// src: LIB [0x009d6e3c]
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB [0x009d6dd8]
extern "C" __declspec(dllimport) void __stdcall AIL_sample_reverb_levels(void* sample, float* dry, float* wet);

// src: GUESS (confidence: medium) [0x00923690]
void __cdecl MSS_GetStreamReverbLevels(void* stream, float* dry, float* wet)
{
    void* sample = AIL_stream_sample_handle(stream);
    AIL_sample_reverb_levels(sample, dry, wet);
}
