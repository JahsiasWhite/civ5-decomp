// c5d-model: claude-opus-5-5
// Free function taking an object pointer: true when the counter at 0x2b88 has
// reached its limit at 0x2b84 and the pending value at 0x2d48 is not positive.
// Owning class is not yet identified, so only the touched fields are laid out.

struct Unk6C5830Obj
{
    char pad0[0x2b84];
    int m_iLimit;       // 0x2b84
    int m_iCount;       // 0x2b88
    char pad2b8c[0x2d48 - 0x2b8c];
    int m_iPending;     // 0x2d48
};

int __stdcall IsCountAtLimitAndIdle(Unk6C5830Obj* pObj)
{
    return pObj->m_iCount >= pObj->m_iLimit && pObj->m_iPending <= 0;
}
