// src: GUESS (confidence: low) [0x004c90a0]
typedef int (__stdcall* UnkCallback_004c90a0)(int);

// src: GUESS (confidence: low) [0x004c90a0]
class UnkCallbackSlot_004c90a0
{
public:
    // Calls the callback with its argument when the slot is armed, and keeps
    // the result.
    // src: GUESS (confidence: low) [0x004c90a0]
    void Fire();

    // src: GUESS (confidence: low)
    int m_enabled;
    // src: GUESS (confidence: low)
    UnkCallback_004c90a0 m_callback;
    // src: GUESS (confidence: low)
    int m_arg;
    // src: GUESS (confidence: low)
    int m_result;
};

void UnkCallbackSlot_004c90a0::Fire()
{
    if (m_enabled && m_callback && m_result)
        m_result = m_callback(m_arg);
}
