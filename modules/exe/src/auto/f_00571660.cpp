// c5d-cflags: -/arch:SSE2   (record copies are rep movsd, not SSE2 movq)
// Swaps two 28-byte records.

// src: GUESS (confidence: low)
struct Record1C_0077cab0
{
    // src: GUESS (confidence: low)
    int m_words[7];
};

// src: GUESS (confidence: low) [0x0077cab0]
void SwapRecords_0077cab0(Record1C_0077cab0& a, Record1C_0077cab0& b)
{
    if (&a != &b)
    {
        Record1C_0077cab0 tmp = a;
        a = b;
        b = tmp;
    }
}
