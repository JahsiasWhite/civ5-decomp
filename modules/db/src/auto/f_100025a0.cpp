// src: GUESS 0x100025a0 (confidence: high)
void FillDwordRange_100025a0(int* first, int* last, const int& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}
