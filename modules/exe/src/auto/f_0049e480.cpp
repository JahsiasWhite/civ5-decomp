// Fills [first, last) of 0x104-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_0049e480
{
    int m_data[0x41];
};

// src: GUESS (confidence: low) [0x0049e480]
void FillRecords_0049e480(Record_0049e480* first, Record_0049e480* last, const Record_0049e480* value)
{
    for (; first != last; ++first)
        *first = *value;
}
