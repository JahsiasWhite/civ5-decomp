// src: LIB [0x009d6d88]
extern "C" __declspec(dllimport) void* __stdcall AIL_set_sample_processor(void* sample, int stage, void* provider);

// src: GUESS (confidence: medium) [0x00923160]
bool __cdecl MSS_SetSampleProcessor(void* sample, int stage, void* provider)
{
    if (!provider)
        return false;
    AIL_set_sample_processor(sample, stage, provider);
    return true;
}
