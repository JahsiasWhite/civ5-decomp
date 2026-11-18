// c5d-cflags: -/arch:SSE2
// Fills [first, last) of 16-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_00789f80
{
    int m_data[4];
};

// src: GUESS (confidence: low) [0x00789f80]
void FillRecords_00789f80(Record_00789f80* first, Record_00789f80* last, const Record_00789f80* value)
{
    for (; first != last; ++first)
        *first = *value;
}
