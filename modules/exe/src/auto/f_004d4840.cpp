// src: GUESS (confidence: low)
class Base_004d4840
{
public:
    // src: GUESS (confidence: low)
    Base_004d4840() : m_f04(2), m_f08(0), m_f0c(0xd) {}
    // src: GUESS (confidence: low)
    virtual void Vfunc0();

private:
    int m_f04;  // +0x04
    int m_f08;  // +0x08
    int m_f0c;  // +0x0c
};

// src: GUESS (confidence: low) [0x004d4840]
class Unk_004d4840 : public Base_004d4840
{
public:
    // src: GUESS (confidence: high) [0x004d4840]
    Unk_004d4840();
    // src: GUESS (confidence: low)
    virtual void Vfunc0();
};

// src: GUESS (confidence: high) [0x004d4840]
Unk_004d4840::Unk_004d4840()
    : Base_004d4840()
{
}
