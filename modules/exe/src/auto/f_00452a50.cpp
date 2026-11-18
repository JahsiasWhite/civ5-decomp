// c5d-cflags: -/arch:SSE2
// Fills [first, last) of 20-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_00452a50
{
    int m_data[5];
};

// src: GUESS (confidence: low) [0x00452a50]
void FillRecords_00452a50(Record_00452a50* first, Record_00452a50* last, const Record_00452a50* value)
{
    for (; first != last; ++first)
        *first = *value;
}
