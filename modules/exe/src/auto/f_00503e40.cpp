// src: GUESS (confidence: low)
struct UnkElem_00503e40
{
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void V8() {}
    virtual void V9(float a, float b) {}
};

// src: GUESS (confidence: low)
struct UnkOwner_00503e40
{
    char m_pad[0x50];
    UnkElem_00503e40** m_begin;
    UnkElem_00503e40** m_end;
};

// src: GUESS (confidence: medium) [0x00503e40]
void __stdcall NotifyAll_00503e40(UnkOwner_00503e40* owner, float a, float b)
{
    for (UnkElem_00503e40** it = owner->m_begin; it != owner->m_end; ++it)
        (*it)->V9(a, b);
}
