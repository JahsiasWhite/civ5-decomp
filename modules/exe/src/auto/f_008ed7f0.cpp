// Fills [first, last) of 0x44-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_008ed7f0
{
    int m_data[0x11];
};

// src: GUESS (confidence: low) [0x008ed7f0]
void FillRecords_008ed7f0(Record_008ed7f0* first, Record_008ed7f0* last, const Record_008ed7f0* value)
{
    for (; first != last; ++first)
        *first = *value;
}
