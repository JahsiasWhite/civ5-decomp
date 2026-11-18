// src: GUESS 0x1000cbf0 (confidence: high)
int* CopyDwordBackward_1000cbf0(const int* first, const int* last, int* destEnd) {
    const int* cur = last;
    while (first != cur) {
        *--destEnd = *--cur;
    }
    return destEnd;
}
