// src: GUESS 0x10003330 (confidence: high)
int* CopyDwordBackward_10003330(const int* first, const int* last, int* destEnd) {
    const int* cur = last;
    while (first != cur) {
        *--destEnd = *--cur;
    }
    return destEnd;
}
