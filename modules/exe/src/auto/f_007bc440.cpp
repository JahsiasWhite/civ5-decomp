// src: EXE [0x007bc440]
// c5d-cflags: -/EHsc
#include "captured_exception.h"

// src: EXE [0x00cb1484]
extern void (__cdecl* g_freeHook_00cb1484)(void*);

namespace tbb {

captured_exception::~captured_exception() {
    if (m_szName_0c != 0) {
        (*g_freeHook_00cb1484)(m_szName_0c);
    }
    if (m_szReason_10 != 0) {
        (*g_freeHook_00cb1484)(m_szReason_10);
    }
}

}  // namespace tbb
