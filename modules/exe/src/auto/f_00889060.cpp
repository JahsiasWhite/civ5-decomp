// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_position(void* sample, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_00889060
{
    float x, y, z;
};

// src: LIB [0x00889060]
void SetSample3DPosition_00889060(void* sample, const Vec3_00889060* pos)
{
    AIL_set_sample_3D_position(sample, pos->x, pos->z, pos->y);
}
