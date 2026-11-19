// src: LIB [0x009d6d8c]
extern "C" __declspec(dllimport) int __stdcall AIL_set_named_sample_file(void* sample, const char* suffix, const void* image, unsigned int size, int block);

// src: GUESS (confidence: medium) [0x00923180]
int __cdecl MSS_SetNamedSampleFile(void* sample, const void* image, unsigned int size, const char* suffix)
{
    return AIL_set_named_sample_file(sample, suffix, image, size, 0);
}
