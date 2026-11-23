// src: GUESS (confidence: low)
class RefObj_0083e0a0 {
public:
    virtual ~RefObj_0083e0a0() {}
    int m_refCount;
};

// src: GUESS (confidence: low)
class Holder_0083e0a0 {
public:
    // src: GUESS (confidence: low) [0x0083e0a0]
    bool GetRef(RefObj_0083e0a0** ppOut, int unused);

private:
    char m_pad[0x18];
    RefObj_0083e0a0* m_pObj;
};

bool Holder_0083e0a0::GetRef(RefObj_0083e0a0** ppOut, int unused)
{
    (void)unused;
    if (ppOut == 0) {
        return true;
    }
    RefObj_0083e0a0* pNew = m_pObj;
    if (*ppOut != pNew) {
        if (pNew != 0) {
            ++pNew->m_refCount;
        }
        RefObj_0083e0a0* pOld = *ppOut;
        if (pOld != 0) {
            if (--pOld->m_refCount <= 0) {
                delete pOld;
            }
        }
        *ppOut = m_pObj;
    }
    return true;
}
