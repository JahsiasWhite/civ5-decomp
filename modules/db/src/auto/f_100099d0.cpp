// src: GUESS 0x100099d0 (confidence: high)
const char* __stdcall SkipCData_100099d0(const char** cursor) {
    while (**cursor != ']' || (*cursor)[1] != ']' || (*cursor)[2] != '>') {
        if (**cursor == 0) {
            return 0;
        }
        ++(*cursor);
    }
    *cursor += 3;
    return 0;
}
