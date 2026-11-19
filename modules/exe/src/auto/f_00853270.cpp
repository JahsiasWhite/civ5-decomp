// Fills [first, last) of 0x48-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_006da970
{
    int m_data[0x12];
};

// src: GUESS (confidence: low) [0x006da970]
void FillRecords_006da970(Record_006da970* first, Record_006da970* last, const Record_006da970* value)
{
    for (; first != last; ++first)
        *first = *value;
}
