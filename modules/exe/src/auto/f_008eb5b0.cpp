// Forwards to the seventh virtual of the object held at offset 0x28c.

// src: GUESS (confidence: low)
class Target_008eb5b0
{
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    // src: GUESS (confidence: low)
    virtual void V6(int arg);
};

// src: GUESS (confidence: low)
class Owner_008eb5b0
{
public:
    // src: GUESS (confidence: low) [0x008eb5b0]
    void Forward(int arg);

    char m_pad0[0x28c];
    // src: GUESS (confidence: low)
    Target_008eb5b0* m_target;
};

void Owner_008eb5b0::Forward(int arg)
{
    m_target->V6(arg);
}
