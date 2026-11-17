// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Delegate: calls the stored member function on the stored target object.

// src: GUESS (confidence: low)
struct Target_007c2df0
{
    int unused;
};

// src: GUESS (confidence: low)
struct Delegate_007c2df0
{
    char m_pad0[0xc];
    // src: GUESS (confidence: low)
    Target_007c2df0* m_target;
    // src: GUESS (confidence: low)
    void (Target_007c2df0::*m_method)(int arg);

    // src: GUESS (confidence: low) [0x007c2df0]
    void Invoke(int arg);
};

void Delegate_007c2df0::Invoke(int arg)
{
    (m_target->*m_method)(arg);
}
