#pragma once
// c5d-vtable: 0x00a72c88

// A callback holder: an object and a member function to call on it, fired when
// the holder is destroyed (0x00761b00). Its constructor (0x004c2cc0) declares the
// same layout in its own file. The vtable pointer is set through a declared array
// until the virtuals are known.

// src: GUESS (confidence: medium) [0x00a72c88]
extern const void* const kVtable_00a72c88[];

// src: GUESS (confidence: low) [0x00761b00]
class UnkCallbackTarget_004c2cc0 {};
typedef void (UnkCallbackTarget_004c2cc0::*UnkCallbackFn_004c2cc0)();

// An object plus a member function to call on it; empty when both are null.
// src: GUESS (confidence: medium) [0x00761b00]
struct UnkDelegate_004c2cc0
{
    bool IsEmpty() const { return !m_target && !m_callback; }
    void operator()() const { (m_target->*m_callback)(); }

    UnkCallbackTarget_004c2cc0* m_target;
    UnkCallbackFn_004c2cc0 m_callback;
};

// src: GUESS (confidence: medium) [0x004c2cc0]
class Class_004c2cc0
{
public:
    // src: GUESS (confidence: medium) [0x00761b00]
    void Destroy();

    const void* const* vtable;
    UnkDelegate_004c2cc0 m_onDestroy;       // 0x04
    int m_fc;
};
