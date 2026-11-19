// Miles Sound System: sets a sample's 3D sound cone (angles in degrees).

// src: LIB
extern "C" __declspec(dllimport) void __stdcall AIL_set_sample_3D_cone(void* sample, float innerAngle, float outerAngle, float outerVolume);

// src: GUESS (confidence: low) [0x00923570]
void SetSampleCone_00923570(void* sample, int innerAngle, int outerAngle, float outerVolume)
{
    AIL_set_sample_3D_cone(sample, (float)innerAngle, (float)outerAngle, outerVolume);
}
