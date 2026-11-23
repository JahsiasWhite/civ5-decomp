// src: GUESS (confidence: low)
struct UnknownItem_00447b40;

// src: GUESS (confidence: low)
class UnknownNode_00447b40 {
public:
    // src: GUESS (confidence: low) [0x00447b40]
    void Dispatch(UnknownItem_00447b40* pItem);

private:
    void* vftable;
    int m_pad04[3];
    UnknownNode_00447b40* m_pChild;
};

// src: GUESS (confidence: low)
struct UnknownItem_00447b40 {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(UnknownNode_00447b40* pNode);

    int m_pad04[3];
    int m_iValue;
    int m_pad14[6];
    bool m_bFlag;
};

void UnknownNode_00447b40::Dispatch(UnknownItem_00447b40* pItem)
{
    if (pItem->m_iValue >= 1000) {
        if (this != 0 && !pItem->m_bFlag) {
            pItem->vfunc4(this);
            pItem->m_bFlag = true;
        }
    } else {
        UnknownNode_00447b40* pChild = m_pChild;
        if (pChild != 0) {
            typedef void (__thiscall *VFunc20Fn)(UnknownNode_00447b40*, UnknownItem_00447b40*);
            VFunc20Fn fn = ((VFunc20Fn**)pChild)[0][20];
            fn(pChild, pItem);
        }
    }
}
