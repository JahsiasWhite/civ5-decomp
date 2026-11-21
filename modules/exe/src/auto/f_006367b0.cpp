// src: GUESS (confidence: low)
struct UnkObj_006367b0
{
    char m_pad[0x70];
    int m_a;
    int m_b;
};

// src: GUESS (confidence: medium) [0x006367b0]
bool __stdcall IsValid_006367b0(UnkObj_006367b0* p)
{
    int a = p->m_a;
    if (a == 0x578 || a == 0x5aa || a == 0x460 ||
        (a == 0 && (p->m_b == 0x578 || p->m_b == 0x5aa || p->m_b == 0x460)))
        return true;
    return false;
}
