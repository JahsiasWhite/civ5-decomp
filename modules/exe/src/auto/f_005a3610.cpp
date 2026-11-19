// c5d-cflags: -/arch:SSE2   (record copies are dword moves, not SSE2 movq)
// Fills a range of 24-byte records with one value.

// src: GUESS (confidence: low)
struct Record24_005a3610
{
    // src: GUESS (confidence: low)
    int m_00;
    // src: GUESS (confidence: low)
    int m_04;
    // src: GUESS (confidence: low)
    int m_08;
    // src: GUESS (confidence: low)
    int m_0c;
    // src: GUESS (confidence: low)
    int m_10;
    // src: GUESS (confidence: low)
    int m_14;
};

// src: GUESS (confidence: low) [0x005a3610]
void FillRecords_005a3610(Record24_005a3610* first, Record24_005a3610* last, const Record24_005a3610& value)
{
    for (; first != last; ++first)
    {
        *first = value;
    }
}
