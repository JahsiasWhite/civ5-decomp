// c5d-model: Gemini 3.8 Flash

// src: LIB [0x009d6d48]
extern "C" __declspec(dllimport) void __stdcall AIL_set_3D_doppler_factor(void* h, float factor);

// src: GUESS (confidence: high) [0x00922fd0]
void SetDopplerFactor_00922fd0(void* h, float factor)
{
    AIL_set_3D_doppler_factor(h, factor);
}
