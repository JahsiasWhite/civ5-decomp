// src: GUESS (confidence: low)
struct TextObj_10008480 {
    // src: GUESS (confidence: low)
    virtual void Slot0() = 0;
    // src: GUESS (confidence: low)
    virtual void GetSpan(const char*& outPtr, unsigned int& outLen) = 0;
    // src: GUESS 0x10008480 (confidence: medium)
    bool GetAsciiSpan(const char*& outPtr, unsigned int& outLen);
};

bool TextObj_10008480::GetAsciiSpan(const char*& outPtr, unsigned int& outLen) {
    const char* ptr;
    unsigned int len;
    GetSpan(ptr, len);
    const char* end = ptr + len;
    const char* p = ptr;
    for (; p != end; ++p) {
        if ((*p & 0x80) != 0) {
            return false;
        }
    }
    outPtr = ptr;
    outLen = len;
    return true;
}
