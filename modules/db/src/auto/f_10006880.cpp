#include "Database/Results.h"
#include "sqlite3_api.h"

namespace Database {

bool Results::Bind(int iColumn, const wchar_t* wszValue, int iLength, bool bStatic) {
    int iByteLen = (iLength == -1) ? -1 : iLength * 2;
    if (bStatic) {
        return !sqlite3_bind_text16(m_Command.stmt, iColumn, wszValue, iByteLen, (void (*)(void*))-1);
    }
    return !sqlite3_bind_text16(m_Command.stmt, iColumn, wszValue, iByteLen, 0);
}

}  // namespace Database
