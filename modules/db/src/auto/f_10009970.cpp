// src: GUESS 0x10009970 (confidence: medium)
const char* __stdcall SkipProcessingInstruction_10009970(const char** cursor) {
    while (**cursor != '?' || (*cursor)[1] != '>') {
        if (**cursor == 0) {
            return 0;
        }
        ++(*cursor);
    }
    *cursor += 2;
    return 0;
}
