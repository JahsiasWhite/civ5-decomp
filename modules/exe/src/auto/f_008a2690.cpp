// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

extern "C" int rand(void);
extern "C" double sin(double x);
extern "C" double cos(double x);
extern "C" double sqrt(double x);

// src: GUESS (confidence: low)
struct EmitterDesc_008a2690
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0xd4];
    // src: GUESS (confidence: low)
    float m_radiusX;
    // src: GUESS (confidence: low)
    float m_height;
    // src: GUESS (confidence: low)
    float m_radiusZ;
    // src: GUESS (confidence: low)
    float m_spread;
};

// src: GUESS (confidence: low)
struct Emitter_008a2690
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x164];
    // src: GUESS (confidence: low)
    EmitterDesc_008a2690* m_desc;
    // src: GUESS (confidence: low)
    unsigned char m_pad168[0x1d0];
    // src: GUESS (confidence: low)
    float m_scaleX;
    // src: GUESS (confidence: low)
    float m_scaleY;
    // src: GUESS (confidence: low)
    float m_scaleZ;
};

// src: GUESS (confidence: medium) [0x008a2690]
void EmitConeVolume_008a2690(Emitter_008a2690* obj, float* outPos, float* outDir)
{
    float v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13;

    v5 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_radiusX * obj->m_scaleX);
    v8 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_radiusZ * obj->m_scaleZ);
    v9 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_height * obj->m_scaleY + (double)0.00001f);
    v4 = (float)((rand() % 100) * (double)0.01f * v9);
    v1 = (float)((rand() % 100) * (double)0.01f * 2.0 * (double)3.1415927f);
    v11 = (float)sin(v1);
    v6 = (float)cos(v1);
    if (v9 > (double)0.0001f || v9 < (double)-0.0001f)
    {
        outPos[0] = (v5 - (v5 * v4) / v9) * v6;
        outPos[2] = (v8 - (v8 * v4) / v9) * v11;
        outPos[1] = v4;
    }
    else
    {
        outPos[0] = 0.0f;
        outPos[2] = 0.0f;
        outPos[1] = v4;
    }
    v12 = (float)((rand() % 100) * (double)0.01f * 2.0 * (double)3.1415927f);
    v2 = (float)((rand() % 100) * (double)0.01f * obj->m_desc->m_spread);
    v3 = (float)cos(v12) * v2;
    v10 = (float)sin(v12) * v2;
    v13 = 10.0f;
    outDir[0] = v3;
    outDir[1] = v13;
    outDir[2] = v10;
    v7 = (float)sqrt(outDir[0] * outDir[0] + outDir[1] * outDir[1] + outDir[2] * outDir[2]);
    if (v7 != 0.0)
    {
        v7 = 1.0f / v7;
        outDir[0] = outDir[0] * v7;
        outDir[1] = outDir[1] * v7;
        outDir[2] = outDir[2] * v7;
    }
}
