// src: GUESS 0x1000ac80 (confidence: medium)
const char* __stdcall SkipProcessingInstruction_1000ac80(const char** cursor) {
    while (**cursor != '?' || (*cursor)[1] != '>') {
        if (**cursor == 0) {
            return 0;
        }
        ++(*cursor);
    }
    *cursor += 2;
    return 0;
}
