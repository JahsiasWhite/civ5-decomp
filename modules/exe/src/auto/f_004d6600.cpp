// c5d-cflags: +/GS-
#include <string.h>

extern "C" {
// src: LIB
__declspec(dllimport) void __stdcall PathRemoveBlanksW(wchar_t* pszPath);
// src: LIB
__declspec(dllimport) int __stdcall PathCanonicalizeW(wchar_t* pszBuf, const wchar_t* pszPath);
}

// src: GUESS (confidence: low)
struct PathBuf_004d6600 {
    wchar_t m_path[260];

    void Normalize();
};

// src: GUESS (confidence: medium) [0x004d6600]
void PathBuf_004d6600::Normalize() {
    PathRemoveBlanksW(m_path);
    wchar_t buf[260] = { 0 };
    if (PathCanonicalizeW(buf, m_path) == 1) {
        memcpy(m_path, buf, sizeof(m_path));
    }
}
