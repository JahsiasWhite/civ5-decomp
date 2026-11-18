// src: GUESS (confidence: low) [0x00490310]
struct CopyStruct_00490310 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;

    // src: GUESS (confidence: medium) [0x00490310]
    CopyStruct_00490310(const CopyStruct_00490310& other);
};

// src: GUESS (confidence: medium) [0x00490310]
CopyStruct_00490310::CopyStruct_00490310(const CopyStruct_00490310& other)
    : m_00(other.m_00)
    , m_04(other.m_04)
    , m_08(other.m_08)
    , m_0c(other.m_0c)
    , m_10(other.m_10)
    , m_14(other.m_14)
    , m_18(other.m_18)
    , m_1c(other.m_1c)
    , m_20(other.m_20)
    , m_24(other.m_24)
    , m_28(other.m_28)
    , m_2c(0)
    , m_30(other.m_30)
{
}
