// src: GUESS 0x1000c880 (confidence: high)
void FillDwordRange_1000c880(int* first, int* last, const int& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}
