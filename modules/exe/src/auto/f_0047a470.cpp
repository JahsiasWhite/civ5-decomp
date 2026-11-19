extern "C" {
// src: LIB
__declspec(dllimport) int __cdecl strncmp(const char* str1, const char* str2, unsigned int maxCount);
}

// src: GUESS (confidence: low) [0x0082ce50]
struct StringSource_0082ce50 {
    // src: GUESS (confidence: low)
    virtual bool GetText(const char** outPtr, unsigned int* outLen);

    // src: GUESS (confidence: medium) [0x0082ce50]
    bool Matches(const char* ptr, const unsigned int& len);
};

// src: GUESS (confidence: medium) [0x0082ce50]
bool StringSource_0082ce50::Matches(const char* ptr, const unsigned int& len) {
    unsigned int myLen;
    const char* myPtr;
    if (GetText(&myPtr, &myLen) && myLen == len && strncmp(myPtr, ptr, len) == 0) {
        return true;
    }
    return false;
}
