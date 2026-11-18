// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

extern "C" int rand(void);
extern "C" double sin(double x);
extern "C" double cos(double x);
extern "C" double sqrt(double x);

// src: GUESS (confidence: low)
struct EmitterDesc_008a2470
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0xd4];
    // src: GUESS (confidence: low)
    float m_radiusX;
    // src: GUESS (confidence: low)
    float m_radiusY;
    // src: GUESS (confidence: low)
    float m_radiusZ;
};

// src: GUESS (confidence: low)
struct Emitter_008a2470
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x164];
    // src: GUESS (confidence: low)
    EmitterDesc_008a2470* m_desc;
    // src: GUESS (confidence: low)
    unsigned char m_pad168[0x1d0];
    // src: GUESS (confidence: low)
    float m_scaleX;
    // src: GUESS (confidence: low)
    float m_scaleY;
    // src: GUESS (confidence: low)
    float m_scaleZ;
};

// src: GUESS (confidence: medium) [0x008a2470]
void EmitSpherePoint_008a2470(Emitter_008a2470* obj, float* outPos, float* outDir)
{
    float v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13;

    v1 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_radiusX * obj->m_scaleX);
    v12 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_radiusY * obj->m_scaleY);
    v5 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_radiusZ * obj->m_scaleZ);
    v2 = (float)((rand() % 100) * (double)0.01f * (double)3.1415927f);
    v10 = (float)((rand() % 100) * (double)0.01f * 2.0 * (double)3.1415927f);
    v11 = (float)sin(v10);
    v8 = (float)sin(v2);
    v6 = (float)cos(v10);
    v13 = (float)cos(v2);
    outPos[0] = v1 * v11 * v13;
    outPos[2] = v12 * v11 * v8;
    outPos[1] = v5 * v6;
    v3 = outPos[0];
    v9 = outPos[1];
    v4 = outPos[2];
    outDir[0] = v3;
    outDir[1] = v9;
    outDir[2] = v4;
    v7 = (float)sqrt(outDir[0] * outDir[0] + outDir[1] * outDir[1] + outDir[2] * outDir[2]);
    if (v7 != 0.0)
    {
        v7 = 1.0f / v7;
        outDir[0] = outDir[0] * v7;
        outDir[1] = outDir[1] * v7;
        outDir[2] = outDir[2] * v7;
    }
}
