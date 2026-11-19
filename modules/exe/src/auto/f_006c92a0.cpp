// Constructs the record with its defaults: no index, visible, half scale.

// src: GUESS (confidence: low)
struct Record_006a4790
{
    // src: GUESS (confidence: low) [0x006a4790]
    Record_006a4790();

    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    int m_index;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    // src: GUESS (confidence: low)
    bool m_visible;
    bool m_25;
    // src: GUESS (confidence: low)
    float m_scale;
};

Record_006a4790::Record_006a4790()
    : m_00(0)
    , m_04(0)
    , m_index(-1)
    , m_0c(0)
    , m_10(0)
    , m_14(0)
    , m_18(0)
    , m_1c(0)
    , m_20(0)
    , m_visible(true)
    , m_25(false)
    , m_scale(0.5f)
{
}
