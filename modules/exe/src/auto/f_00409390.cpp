// c5d-cflags: +/Oy-
// Delegate: calls the stored member function on the stored target object.

// src: GUESS (confidence: low)
struct Target_007c2e00 {
    int unused;
};

class Host_007c2e00 {
public:
    char m_pad0[0xc];
    // src: GUESS (confidence: low)
    Target_007c2e00* m_target;
    // src: GUESS (confidence: low)
    void (Target_007c2e00::*m_method)(int a);

    // src: GUESS (confidence: high) [0x007c2e00]
    void __thiscall InvokeCallback(int a, int b, int c, int d);
};

void __thiscall Host_007c2e00::InvokeCallback(int a, int b, int c, int d) {
    (m_target->*m_method)(a);
}
