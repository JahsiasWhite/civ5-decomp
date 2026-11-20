// src: GUESS (confidence: low) [0x02ea20ec]
extern void* g_unkObj_02ea20ec;

// src: GUESS (confidence: low) [0x0081cb80]
extern void UnkGetFloat_0081cb80(void* obj, float* outVal);

// src: GUESS (confidence: medium) [0x008213a0]
float GetGlobalFloat_008213a0()
{
    float val = 0.0f;
    if (g_unkObj_02ea20ec)
        UnkGetFloat_0081cb80(g_unkObj_02ea20ec, &val);
    return val;
}
