// src: GUESS (confidence: low)
class RefObj_00847640 {
public:
    virtual ~RefObj_00847640() {}
    int m_refCount;
};

// src: GUESS (confidence: low)
class Holder_00847640 {
public:
    // src: GUESS (confidence: low) [0x00847640]
    bool GetRef(RefObj_00847640** ppOut, int unused);

private:
    char m_pad[0x1c];
    RefObj_00847640* m_pObj;
};

bool Holder_00847640::GetRef(RefObj_00847640** ppOut, int unused)
{
    (void)unused;
    if (ppOut == 0) {
        return true;
    }
    RefObj_00847640* pNew = m_pObj;
    if (*ppOut != pNew) {
        if (pNew != 0) {
            ++pNew->m_refCount;
        }
        RefObj_00847640* pOld = *ppOut;
        if (pOld != 0) {
            if (--pOld->m_refCount <= 0) {
                delete pOld;
            }
        }
        *ppOut = m_pObj;
    }
    return true;
}
