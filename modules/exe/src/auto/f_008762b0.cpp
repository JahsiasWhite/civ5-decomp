// Fills a range of 28-byte records with one value.

// src: GUESS (confidence: low)
struct Record1C_009102d0
{
    // src: GUESS (confidence: low)
    int m_words[7];
};

// src: GUESS (confidence: low) [0x009102d0]
void FillRecords_009102d0(Record1C_009102d0* first, Record1C_009102d0* last, const Record1C_009102d0& value)
{
    for (; first != last; ++first)
    {
        *first = value;
    }
}
