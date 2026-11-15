// c5d-model: claude-opus-5-5
// Returns a field of the owned object when its pointer list is non-empty.

struct Holder008eb1d0Inner
{
    char pad0[0x74];
    void** m_listBegin;
    void** m_listEnd;
    void* pad7c;
    void* m_current;
};

struct Holder008eb1d0
{
    void* pad0;
    Holder008eb1d0Inner* m_inner;

    void* GetCurrentIfAny();
};

void* Holder008eb1d0::GetCurrentIfAny()
{
    Holder008eb1d0Inner* inner = m_inner;
    if (inner != 0 && (unsigned int)(inner->m_listEnd - inner->m_listBegin) > 0)
        return inner->m_current;
    return 0;
}
