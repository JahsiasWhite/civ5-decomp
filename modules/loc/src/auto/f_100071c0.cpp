// src: GUESS (confidence: medium) [0x100071c0]
#include <memory>

namespace {

// src: GUESS (confidence: low)
typedef void (__cdecl* FreeDeleterFn)(void*);

}  // namespace

// src: GUESS (confidence: medium) [0x100071c0]
std::tr1::shared_ptr<const char> MakeSharedBuffer_100071c0(char* szPtr, FreeDeleterFn pfn) {
    return std::tr1::shared_ptr<const char>(szPtr, pfn);
}
