// c5d-model: claude-opus-5-5
// Getter returning three fields of an unidentified object through out-params.

class CTripleFieldOwner_0061b050
{
public:
    void GetValues(int* pA, int* pB, int* pC) const;

private:
    char m_pad0[0x1c];
    int m_iA;      // 0x1c
    int m_iB;      // 0x20
    int m_pad24;   // 0x24
    int m_iC;      // 0x28
};

void CTripleFieldOwner_0061b050::GetValues(int* pA, int* pB, int* pC) const
{
    *pA = m_iA;
    *pB = m_iB;
    *pC = m_iC;
}
