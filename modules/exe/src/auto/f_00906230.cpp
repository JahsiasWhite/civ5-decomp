// While active, stores the value and passes it to the voice.

// src: GUESS (confidence: low)
class Voice_00906230
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
    virtual void v09();
    // src: GUESS (confidence: low)
    virtual void SetPitch(float value);
};

// src: GUESS (confidence: low)
class Sound_00906230
{
public:
    // src: GUESS (confidence: low) [0x00906230]
    void SetPitch(float value);

    char m_pad0[0x9c];
    // src: GUESS (confidence: low)
    Voice_00906230* m_voice;
    char m_padA0[0xb4 - 0xa0];
    // src: GUESS (confidence: low)
    float m_value;
    char m_pad[0xc0 - 0xb4 - 4];
    // src: GUESS (confidence: low)
    bool m_active;
};

void Sound_00906230::SetPitch(float value)
{
    if (m_active)
    {
        m_value = value;
        m_voice->SetPitch(value);
    }
}
