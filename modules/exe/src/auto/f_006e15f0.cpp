// Stores an 8-byte pair into the object and forwards it to a virtual handler.

struct IntPair
{
    int a;
    int b;
};

class PairForwarder
{
public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void OnPairChanged(const IntPair* pair);

    void SetPair(const IntPair& pair);

private:
    IntPair m_pair;
};

void PairForwarder::SetPair(const IntPair& pair)
{
    m_pair = pair;
    OnPairChanged(&m_pair);
}
