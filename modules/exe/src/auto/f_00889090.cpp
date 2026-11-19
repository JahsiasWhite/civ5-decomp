// Miles Sound System (y-up, so the game's y and z swap): sets the 3D position of a stream's sample.

// src: LIB
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_position(void* sample, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_00923490
{
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low) [0x00923490]
void SetStream3D_00923490(void* stream, const Vec3_00923490* v)
{
    AIL_set_sample_3D_position(AIL_stream_sample_handle(stream), v->x, v->z, v->y);
}
