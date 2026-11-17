// c5d-model: Gemini 4 Hydrogen
class RefCounted_0075c220 {
public:
    virtual void __thiscall Destroy(int flags);
    int m_refCount;
};

class Host_0075c220 {
public:
    RefCounted_0075c220* m_obj;
    // src: GUESS (confidence: high) [0x0075c220]
    void __thiscall Release();
};

void Host_0075c220::Release() {
    RefCounted_0075c220* p = m_obj;
    if (p) {
        --p->m_refCount;
        if (p->m_refCount <= 0) {
            p->Destroy(1);
        }
    }
}
