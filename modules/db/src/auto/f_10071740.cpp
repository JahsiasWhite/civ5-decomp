// c5d-cflags: -/EHsc
#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/XMLSerializer.h"

namespace Database {

void XMLSerializer::SetPackageTag(const char* szPackageTag) {
    if (szPackageTag != 0) {
        m_strPackageTag = szPackageTag;
    } else {
        m_strPackageTag.clear();
    }
}

}  // namespace Database
