#include "Database/Results.h"

// src: GUESS (confidence: low)
extern "C" int g_alloc_100789b8;
// src: GUESS (confidence: low)
void Free_1000ecc0(void* p);
// src: GUESS (confidence: low)
const char* DupStr_10025040(void* alloc, const char* s);

namespace Database {

void Results::SetColumns(const char* szColumns) {
    if (m_szColumns != 0) {
        Free_1000ecc0((void*)m_szColumns);
    }
    m_szColumns = 0;
    if (szColumns != 0) {
        m_szColumns = DupStr_10025040(&g_alloc_100789b8, szColumns);
    }
}

}  // namespace Database
