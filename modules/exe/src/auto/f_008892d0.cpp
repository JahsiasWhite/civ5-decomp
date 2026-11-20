// src: LIB [0x00939ddc]
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB [0x00939d6c]
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_reverb_levels(void* sample, float dry, float wet);

// src: GUESS (confidence: high) [0x008892d0]
void SetStreamReverbLevels_008892d0(void* stream, float dry, float wet)
{
    void* sample = AIL_stream_sample_handle(stream);
    AIL_set_sample_reverb_levels(sample, dry, wet);
}
