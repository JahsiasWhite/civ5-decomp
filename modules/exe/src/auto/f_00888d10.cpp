// src: LIB [0x009d6d7c]
extern "C" __declspec(dllimport) void __stdcall AIL_stop_sample(void* sample);
// src: LIB [0x009d6d84]
extern "C" __declspec(dllimport) void __stdcall AIL_resume_sample(void* sample);

// src: GUESS (confidence: medium) [0x00923120]
void __cdecl MSS_PauseSample(void* sample, bool paused)
{
    if (paused)
        AIL_stop_sample(sample);
    else
        AIL_resume_sample(sample);
}
