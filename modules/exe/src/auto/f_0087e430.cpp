// Fills [first, last) of 12-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_009185e0
{
    int a;
    int b;
    int c;
};

// src: GUESS (confidence: low) [0x009185e0]
void FillRecords(Record_009185e0* first, Record_009185e0* last, const Record_009185e0* value)
{
    for (; first != last; ++first)
        *first = *value;
}
