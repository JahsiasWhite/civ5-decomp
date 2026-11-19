// src: GUESS (confidence: medium)
struct Stream_0082bde0 {
    // src: GUESS (confidence: medium) [0x0082bde0]
    void ReadInt(int* out);
};

// src: GUESS (confidence: medium) [0x006d7db0]
Stream_0082bde0& ReadIntOp_006d7db0(Stream_0082bde0& stream, int& out) {
    int val;
    stream.ReadInt(&val);
    out = val;
    return stream;
}
