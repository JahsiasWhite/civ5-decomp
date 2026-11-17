// Calls an inherited virtual of the second base class: the call goes through
// that base's vtable with `this` adjusted to the base subobject.

// src: GUESS (confidence: low)
class BaseA_0073bc00
{
public:
    virtual void A0();
};

// src: GUESS (confidence: low)
class BaseB_0073bc00
{
public:
    virtual void B0();
    virtual void B1();
    // src: GUESS (confidence: low)
    virtual void B2(int arg);
};

// src: GUESS (confidence: low)
class Derived_0073bc00 : public BaseA_0073bc00, public BaseB_0073bc00
{
public:
    // src: GUESS (confidence: low) [0x0073bc00]
    void CallB2(int arg);
};

void Derived_0073bc00::CallB2(int arg)
{
    B2(arg);
}
