// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_velocity_vector(void* sample, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_008890c0
{
    float x, y, z;
};

// src: LIB [0x008890c0]
void SetSample3DVelocityVector_008890c0(void* sample, const Vec3_008890c0* vel)
{
    AIL_set_sample_3D_velocity_vector(sample, vel->x, vel->z, vel->y);
}
