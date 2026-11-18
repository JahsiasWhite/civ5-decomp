// c5d-cflags: -/arch:SSE2
// Copies the 4-part default value from globals.

// src: GUESS (confidence: low)
struct Value16_005c8000
{
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

// src: GUESS (confidence: low) [0x00a5559c]
extern const int g_defaultA_00a5559c;
// src: GUESS (confidence: low) [0x00a555a0]
extern const int g_defaultB_00a555a0;
// src: GUESS (confidence: low) [0x00a555a4]
extern const int g_defaultC_00a555a4;
// src: GUESS (confidence: low) [0x00a555a8]
extern const int g_defaultD_00a555a8;

// src: GUESS (confidence: low) [0x005c8000]
void __stdcall GetDefault_005c8000(Value16_005c8000* out)
{
    out->m_a = g_defaultA_00a5559c;
    out->m_b = g_defaultB_00a555a0;
    out->m_c = g_defaultC_00a555a4;
    out->m_d = g_defaultD_00a555a8;
}
