// Fills [first, last) of 0x40-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_0073d740
{
    int m_data[0x10];
};

// src: GUESS (confidence: low) [0x0073d740]
void FillRecords_0073d740(Record_0073d740* first, Record_0073d740* last, const Record_0073d740* value)
{
    for (; first != last; ++first)
        *first = *value;
}
