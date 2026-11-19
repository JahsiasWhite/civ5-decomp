// Constructs the record from its 0x44-byte base data, with the four extra
// floats cleared.

// src: GUESS (confidence: low)
struct BaseData_005c84b0
{
    int m_data[0x11];
};

// src: GUESS (confidence: low)
struct Record_005c84b0 : public BaseData_005c84b0
{
    // src: GUESS (confidence: low) [0x005c84b0]
    Record_005c84b0(const BaseData_005c84b0& base);

    float m_a;
    float m_b;
    float m_c;
    float m_d;
};

Record_005c84b0::Record_005c84b0(const BaseData_005c84b0& base)
    : BaseData_005c84b0(base)
    , m_a(0.0f)
    , m_b(0.0f)
    , m_c(0.0f)
    , m_d(0.0f)
{
}
