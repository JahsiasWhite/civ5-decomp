// c5d-cflags: -/arch:SSE2
// Fills [first, last) of 12-byte records with a copy of `value`.

// src: GUESS (confidence: low)
struct Record_0065acd0
{
    int a;
    int b;
    int c;
};

// src: GUESS (confidence: low) [0x0065acd0]
void FillRecords_0065acd0(Record_0065acd0* first, Record_0065acd0* last, const Record_0065acd0* value)
{
    for (; first != last; ++first)
        *first = *value;
}
