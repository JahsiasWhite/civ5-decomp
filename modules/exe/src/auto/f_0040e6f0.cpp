// c5d-cflags: +/Oy-

// Sets every int in [first, last) to *value.
// src: GUESS (confidence: medium) [0x004fd4a0]
void FillInts_004fd4a0(int* first, int* last, const int* value)
{
    for (; first != last; ++first)
        *first = *value;
}
