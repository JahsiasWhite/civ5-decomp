// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

// src: LIB
extern "C" int rand(void);
// src: LIB
extern "C" double sin(double x);
// src: LIB
extern "C" double cos(double x);
// src: LIB
extern "C" double sqrt(double x);

// src: GUESS (confidence: low)
struct EmitterDesc_008082b0
{
    unsigned char m_pad00[0xd4];
    float m_sizeX;
    float m_sizeY;
    float m_sizeZ;
    float m_spread;
};

// src: GUESS (confidence: low)
struct Emitter_008082b0
{
    unsigned char m_pad00[0x164];
    EmitterDesc_008082b0* m_desc;
    unsigned char m_pad168[0x1d0];
    float m_scaleX;
    float m_scaleY;
    float m_scaleZ;
};

// src: GUESS (confidence: medium) [0x008082b0]
void EmitBoxPoint_008082b0(Emitter_008082b0* obj, float* outPos, float* outDir)
{
    float a1, a2, a3, a4, a5, a6, a7, a8, a9;

    a5 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_sizeX * obj->m_scaleX);
    a2 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_sizeY * obj->m_scaleY);
    a3 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_sizeZ * obj->m_scaleZ);
    outPos[0] = a5 - obj->m_desc->m_sizeX * obj->m_scaleX * 0.5f;
    outPos[1] = a3 - obj->m_desc->m_sizeZ * obj->m_scaleZ * 0.5f;
    outPos[2] = a2 - obj->m_desc->m_sizeY * obj->m_scaleY * 0.5f;
    a4 = (float)((rand() % 100) * (double)0.01f * 2.0 * (double)3.1415927f);
    a7 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_spread);
    a1 = (float)cos(a4) * a7;
    a8 = (float)sin(a4) * a7;
    a9 = 10.0f;
    outDir[0] = a1;
    outDir[1] = a9;
    outDir[2] = a8;
    a6 = (float)sqrt(outDir[0] * outDir[0] + outDir[1] * outDir[1] + outDir[2] * outDir[2]);
    if (a6 != 0.0)
    {
        a6 = 1.0f / a6;
        outDir[0] = outDir[0] * a6;
        outDir[1] = outDir[1] * a6;
        outDir[2] = outDir[2] * a6;
    }
}
