// src: GUESS 0x10009a00 (confidence: high)
const char* __stdcall SkipDecl_10009a00(const char** cursor) {
    while (**cursor != '>') {
        char ch = **cursor;
        if (ch == 0) {
            return 0;
        }
        ++(*cursor);
        if (ch == '[') {
            int depth = 1;
            do {
                switch (**cursor) {
                    case 0:
                        return 0;
                    case '[':
                        ++depth;
                        break;
                    case ']':
                        --depth;
                        break;
                }
                ++(*cursor);
            } while (depth > 0);
        }
    }
    ++(*cursor);
    return 0;
}
