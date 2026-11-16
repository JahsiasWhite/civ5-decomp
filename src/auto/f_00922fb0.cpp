// c5d-model: Gemini 3.8 Flash

// src: LIB [0x009d6d44]
extern "C" __declspec(dllimport) void __stdcall AIL_set_3D_rolloff_factor(void* h, float factor);

// src: GUESS (confidence: high) [0x00922fb0]
void SetRolloffFactor_00922fb0(void* h, float factor)
{
    AIL_set_3D_rolloff_factor(h, factor);
}
