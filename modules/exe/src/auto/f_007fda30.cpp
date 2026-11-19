// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: low)
struct UnkSub_008979a0
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x5c];
    // src: GUESS (confidence: low)
    float m_field5c;
    // src: GUESS (confidence: low)
    unsigned char m_pad60[0x6c];
    // src: GUESS (confidence: low)
    float m_fieldcc;
    // src: GUESS (confidence: low)
    unsigned char m_padd0[0x68];
    // src: GUESS (confidence: low)
    int m_field138;
    // src: GUESS (confidence: low)
    void* m_field13c;
    // src: GUESS (confidence: low)
    unsigned char m_pad140[0x60];
    // src: GUESS (confidence: low)
    float m_field1a0;
};

// src: GUESS (confidence: low)
struct UnkEntry_008979a0
{
    // src: GUESS (confidence: low)
    unsigned int m_ticks;
    // src: GUESS (confidence: low)
    UnkSub_008979a0 m_sub;
};

// src: GUESS (confidence: low)
struct UnkGroup_008979a0
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x24];
    // src: GUESS (confidence: low)
    float m_rate;
    // src: GUESS (confidence: low)
    int m_count;
    // src: GUESS (confidence: low)
    UnkEntry_008979a0** m_entries;
};

// src: GUESS (confidence: medium) [0x008979a0]
float GetMaxDuration_008979a0(UnkSub_008979a0* obj)
{
    UnkGroup_008979a0* v6 = 0;
    UnkEntry_008979a0** v5 = 0;
    UnkSub_008979a0* v4 = 0;
    float v1 = 0.0f;
    float v2 = 0.0f;
    float v7 = 0.0f;
    int i = 0;
    int v3;

    if (!obj)
    {
        return -1.0f;
    }
    if (!obj->m_field138)
    {
        return obj->m_field5c + obj->m_field1a0;
    }
    v6 = (UnkGroup_008979a0*)obj->m_field13c;
    i = v6->m_count;
    if (i < 2)
    {
        return obj->m_field5c + obj->m_field1a0;
    }
    v5 = v6->m_entries;
    if (v6->m_rate <= 0.0)
    {
        return obj->m_field5c + obj->m_field1a0;
    }
    v7 = 1.0f / v6->m_rate;
    for (v3 = 0; v3 < i - 1; ++v3)
    {
        v4 = &v5[v3]->m_sub;
        v2 = (float)(v5[v3 + 1]->m_ticks * v7 + ((v4->m_fieldcc > 0.0) ? (v4->m_field5c + v4->m_field1a0) : 0.0));
        if (v2 > v1)
        {
            v1 = v2;
        }
    }
    v4 = &v5[i - 1]->m_sub;
    v2 = (float)(v5[i - 1]->m_ticks * v7 + ((v4->m_fieldcc > 0.0) ? (v4->m_field5c + v4->m_field1a0) : 0.0));
    if (v2 > v1)
    {
        v1 = v2;
    }
    return v1;
}
