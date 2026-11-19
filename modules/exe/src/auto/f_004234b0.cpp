// src: GUESS (confidence: medium)
struct Stream_0082bde0 {
    // src: GUESS (confidence: medium) [0x0082bde0]
    void ReadInt(int* out);
};

// src: GUESS (confidence: medium) [0x007dac90]
struct Record_007dac90 {
    int m_pad0[5];
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;

    // src: GUESS (confidence: medium) [0x007dac90]
    void ReadFrom(Stream_0082bde0* stream);
};

// src: GUESS (confidence: medium) [0x007dac90]
void Record_007dac90::ReadFrom(Stream_0082bde0* stream) {
    int dummy;
    stream->ReadInt(&dummy);
    stream->ReadInt(&m_28);
    stream->ReadInt(&m_18);
    stream->ReadInt(&m_14);
    stream->ReadInt(&m_20);
    stream->ReadInt(&m_24);
}
