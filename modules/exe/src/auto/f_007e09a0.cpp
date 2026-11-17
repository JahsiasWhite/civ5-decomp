// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Stream_007e09a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void __thiscall Serialize(void* ptr);
};

class Host_007e09a0 {
public:
    char pad0[0x30];
    int m_count;
    int m_field34;
    // src: GUESS (confidence: high) [0x007e09a0]
    Host_007e09a0* __thiscall ReadNext(Stream_007e09a0* s);
};

Host_007e09a0* __thiscall Host_007e09a0::ReadNext(Stream_007e09a0* s) {
    s->Serialize(&m_field34);
    m_count++;
    return this;
}
