// c5d-model: Gemini 3.8 Flash

// src: LIB [0x009d6d40]
extern "C" __declspec(dllimport) void __stdcall AIL_set_3D_distance_factor(void* h, float factor);

// src: GUESS (confidence: high) [0x00922f90]
void SetDistanceFactor_00922f90(void* h, float factor)
{
    AIL_set_3D_distance_factor(h, factor);
}
