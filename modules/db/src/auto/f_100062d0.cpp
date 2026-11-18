#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/BinaryIO.h"

namespace Database {

BinaryIO::BinaryIO(const char* szFilename)
    : m_szFilename(szFilename) {
}

}  // namespace Database
