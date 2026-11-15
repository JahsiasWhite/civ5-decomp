// c5d-model: claude-opus-5-5
// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// A small callback holder: two cleared counters plus a bound
// (object, member-function) pair that is invoked on reset.

class CallbackTarget
{
};

typedef void (CallbackTarget::*CallbackMethod)(int value, int extra);

class BoundCallbackReset
{
public:
    void Reset(int value);

    char m_pad00[0x10];
    int m_first;               // +0x10
    int m_second;              // +0x14
    CallbackTarget *m_target;  // +0x18
    CallbackMethod m_method;   // +0x1c
};

void BoundCallbackReset::Reset(int value)
{
    m_first = 0;
    m_second = 0;
    (m_target->*m_method)(value, 0);
}
