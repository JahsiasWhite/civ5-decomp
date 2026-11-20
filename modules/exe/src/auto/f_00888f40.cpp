// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_volume_pan(void* sample, float volume, float pan);

// src: LIB [0x00888f40]
void SetStreamVolumePan_00888f40(void* stream, float volume, float pan)
{
    AIL_set_sample_volume_pan(AIL_stream_sample_handle(stream), volume, pan);
}
