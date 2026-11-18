// src: GUESS 0x100025c0 (confidence: high)
void FillDwordRange_100025c0(int* first, int* last, const int& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}
