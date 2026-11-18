// src: EXE [0x100737c0]
// c5d-cflags: -/EHsc
#include "Database/XMLSerializer.h"

namespace Database {

void XMLSerializer::RemoveTableFromPackageTagList(const char* szTableName) {
    if (szTableName == 0) {
        return;
    }
    for (std::list<std::string>::iterator it = m_packageTagList.begin();
         it != m_packageTagList.end(); ++it) {
        if (it->compare(szTableName) == 0) {
            m_packageTagList.erase(it);
            return;
        }
    }
}

}  // namespace Database
