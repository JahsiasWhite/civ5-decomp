// Fills [first, last) of 0x5c-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_00628200
{
    int m_data[0x17];
};

// src: GUESS (confidence: low) [0x00628200]
void FillRecords_00628200(Record_00628200* first, Record_00628200* last, const Record_00628200* value)
{
    for (; first != last; ++first)
        *first = *value;
}
