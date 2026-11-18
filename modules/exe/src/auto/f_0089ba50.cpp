// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: low) [0x00c9eca8]
extern float g_00c9eca8;
// src: GUESS (confidence: low) [0x00c9ecac]
extern float g_00c9ecac;
// src: GUESS (confidence: low) [0x00c9ecb0]
extern float g_00c9ecb0;
// src: GUESS (confidence: low) [0x00c9ecb4]
extern float g_00c9ecb4;

// src: GUESS (confidence: low)
struct Unk_0089ba50
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x308];
    // src: GUESS (confidence: low)
    float m_field308;
    // src: GUESS (confidence: low)
    float m_field30c;
    // src: GUESS (confidence: low)
    float m_field310;
    // src: GUESS (confidence: low)
    float m_field314;
    // src: GUESS (confidence: low)
    float m_field318;
};

// src: GUESS (confidence: medium) [0x0089ba50]
void UpdateSmoothing_0089ba50(Unk_0089ba50* obj)
{
    float v1;
    if (obj->m_field308 <= g_00c9ecac)
    {
        v1 = g_00c9ecac;
    }
    else if (obj->m_field308 >= g_00c9ecb0)
    {
        v1 = g_00c9ecb0;
    }
    else
    {
        float v2 = g_00c9ecb4 * obj->m_field308 * obj->m_field308;
        v1 = (g_00c9ecb0 - g_00c9ecac) * v2 + g_00c9ecac;
        if (v1 > g_00c9ecb0)
        {
            v1 = g_00c9ecb0;
        }
        else if (v1 < g_00c9ecac)
        {
            v1 = g_00c9ecac;
        }
    }
    v1 = v1 - g_00c9ecac;
    if (v1 + (double)0.0001f < obj->m_field314 || v1 - (double)0.0001f > obj->m_field314)
    {
        obj->m_field318 = (v1 - obj->m_field310) * g_00c9eca8;
        obj->m_field314 = v1;
    }
    if (obj->m_field310 < obj->m_field314)
    {
        obj->m_field310 = obj->m_field310 + obj->m_field318;
        if (obj->m_field310 > obj->m_field314)
        {
            obj->m_field310 = obj->m_field314;
        }
    }
    if (obj->m_field310 > obj->m_field314)
    {
        obj->m_field310 = (float)(obj->m_field318 * 4.0 + obj->m_field310);
        if (obj->m_field310 < obj->m_field314)
        {
            obj->m_field310 = obj->m_field314;
        }
    }
    obj->m_field30c = 1.0f - obj->m_field310;
}
