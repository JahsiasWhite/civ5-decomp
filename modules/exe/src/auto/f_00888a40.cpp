// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_listener_3D_position(void* driver, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_00888a40
{
    float x, y, z;
};

// src: LIB [0x00888a40]
void SetListener3DPosition_00888a40(void* driver, const Vec3_00888a40* pos)
{
    AIL_set_listener_3D_position(driver, pos->x, pos->z, pos->y);
}
