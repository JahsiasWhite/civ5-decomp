// Takes the lock (left held for the caller), counts the call, and consumes
// the pending flag: true when the object is enabled and a request was
// pending.

#include <windows.h>

// src: GUESS (confidence: low) [0x00b88ac0]
class Worker_00823440
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    // src: GUESS (confidence: low) [0x00823440]
    virtual bool BeginUpdate();

    // src: GUESS (confidence: low)
    bool m_enabled;
    // src: GUESS (confidence: low)
    bool m_pending;
    char m_pad6[0x118 - 6];
    // src: GUESS (confidence: low)
    CRITICAL_SECTION m_lock;
    char m_pad130[0x1d4 - 0x130];
    // src: GUESS (confidence: low)
    int m_updates;
};

bool Worker_00823440::BeginUpdate()
{
    EnterCriticalSection(&m_lock);
    ++m_updates;
    bool result = m_enabled && m_pending;
    m_pending = false;
    return result;
}
