// Reports whether the state field at offset 0x8 equals 3.

// src: GUESS (confidence: low)
class StateOwner_007e5710
{
public:
    // src: GUESS (confidence: low) [0x007e5710]
    bool IsState3() const;

    int m_field0;
    int m_field4;
    // src: GUESS (confidence: low)
    int m_state;
};

bool StateOwner_007e5710::IsState3() const
{
    if (m_state == 3)
        return true;
    return false;
}
