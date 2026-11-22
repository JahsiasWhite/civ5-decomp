// src: GUESS (confidence: low) [0x0047e410]
class Base_0047e410 {
public:
    virtual ~Base_0047e410() {}
    char m_b4;
    int m_i8;
    int m_ic;
    int m_i10;

    Base_0047e410() : m_b4(1), m_i8(1), m_ic(0), m_i10(0) {}
};

// src: GUESS (confidence: low) [0x0047e410]
class Derived_0047e410 : public Base_0047e410 {
public:
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    char m_b24;
    char m_b25;
    int m_i28;
    int m_i2c;

    // src: GUESS (confidence: low) [0x0047e410]
    Derived_0047e410();
};

Derived_0047e410::Derived_0047e410()
    : m_i14(0), m_i18(0), m_i1c(0), m_i20(0), m_b24(1), m_b25(0), m_i28(2), m_i2c(0) {}
