// src: GUESS (confidence: medium) [0x00823600]
struct Entry12 {
    int m_iVal;
    int m_pad4;
    int m_pad8;
};

// src: GUESS (confidence: medium) [0x00823600]
extern Entry12 g_entryTable[];

// src: GUESS (confidence: medium) [0x00823600]
struct IndexHolder10 {
    char m_pad0[0x10];
    int m_iIndex;
};

// src: GUESS (confidence: medium) [0x00823600]
class TargetVtable54 {
public:
    virtual void __cdecl V0();
    virtual void __cdecl V1();
    virtual void __cdecl V2();
    virtual void __cdecl V3();
    virtual void __cdecl V4();
    virtual void __cdecl V5();
    virtual void __cdecl V6();
    virtual void __cdecl V7();
    virtual void __cdecl V8();
    virtual void __cdecl V9();
    virtual void __cdecl V10();
    virtual void __cdecl V11();
    virtual void __cdecl V12();
    virtual void __cdecl V13();
    virtual void __cdecl V14();
    virtual void __cdecl V15();
    virtual void __cdecl V16();
    virtual void __cdecl V17();
    virtual void __cdecl V18();
    virtual void __cdecl V19();
    virtual void __cdecl V20();
    virtual void __cdecl V21();
    virtual void __cdecl V22();
    virtual void __cdecl V23();
    virtual void __cdecl V24();
    virtual void __cdecl V25();
    virtual void __cdecl V26();
    virtual void __cdecl V27();
    virtual void __cdecl V28();
    virtual void __cdecl V29();
    virtual void __cdecl V30();
    virtual void __cdecl V31();
    virtual void __cdecl V32();
    virtual void __cdecl V33();
    virtual void __cdecl V34();
    virtual void __cdecl V35();
    virtual void __cdecl V36();
    virtual void __cdecl V37();
    virtual void __cdecl V38();
    virtual void __cdecl V39();
    virtual void __cdecl V40();
    virtual void __cdecl V41();
    virtual void __cdecl V42();
    virtual void __cdecl V43();
    virtual void __cdecl V44();
    virtual void __cdecl V45();
    virtual void __cdecl V46();
    virtual void __cdecl V47();
    virtual void __cdecl V48();
    virtual void __cdecl V49();
    virtual void __cdecl V50();
    virtual void __cdecl V51();
    virtual void __cdecl V52();
    virtual void __cdecl V53();
    virtual void __cdecl V54(int val);
};

// src: GUESS (confidence: medium) [0x00823600]
void __cdecl ForwardTableVal(TargetVtable54* pTarget, IndexHolder10* pHolder) {
    pTarget->V54(g_entryTable[pHolder->m_iIndex].m_iVal);
}
