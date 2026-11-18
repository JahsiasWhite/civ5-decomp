// Miles Sound System: sets the 3D sound cone of a stream's sample (angles in
// degrees).

// src: LIB
extern "C" __declspec(dllimport) void* __stdcall AIL_stream_sample_handle(void* stream);
// src: LIB
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_cone(void* sample, float innerAngle, float outerAngle, float outerVolume);

// src: GUESS (confidence: low) [0x009235a0]
void SetStreamCone_009235a0(void* stream, int innerAngle, int outerAngle, float outerVolume)
{
    void* sample = AIL_stream_sample_handle(stream);
    AIL_set_sample_3D_cone(sample, (float)innerAngle, (float)outerAngle, outerVolume);
}
