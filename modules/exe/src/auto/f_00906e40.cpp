// c5d-model: Gemini 4 Hydrogen
class RefCounted_00906e40 {
public:
    virtual void __thiscall Destroy(int flags);
    int m_refCount;
};

class Host_00906e40 {
public:
    char pad[0x2c];
    RefCounted_00906e40* m_obj;
    // src: GUESS (confidence: high) [0x00906e40]
    void __thiscall Release();
};

void Host_00906e40::Release() {
    RefCounted_00906e40* p = m_obj;
    if (p) {
        --p->m_refCount;
        if (p->m_refCount <= 0) {
            p->Destroy(1);
        }
    }
}
