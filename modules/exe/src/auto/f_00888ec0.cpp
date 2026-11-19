// src: LIB [0x009d6e3c]
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB [0x009d6dac]
extern "C" __declspec(dllimport) void __stdcall AIL_sample_volume_pan(void* sample, float* volume, float* pan);

// src: GUESS (confidence: medium) [0x009232c0]
void __cdecl MSS_GetStreamVolumePan(void* stream, float* volume, float* pan)
{
    void* sample = AIL_stream_sample_handle(stream);
    AIL_sample_volume_pan(sample, volume, pan);
}
