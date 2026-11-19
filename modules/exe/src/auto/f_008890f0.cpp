// Miles Sound System (y-up, so the game's y and z swap): sets the 3D velocity of a stream's sample.

// src: LIB
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_velocity_vector(void* sample, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_009234f0
{
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low) [0x009234f0]
void SetStream3D_009234f0(void* stream, const Vec3_009234f0* v)
{
    AIL_set_sample_3D_velocity_vector(AIL_stream_sample_handle(stream), v->x, v->z, v->y);
}
