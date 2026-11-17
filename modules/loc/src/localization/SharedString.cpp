#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/SharedString.h"

namespace Localization {

unsigned int SharedString::GetBufferLength() const {
    return m_BufferLength;
}

unsigned int SharedString::GetOffset() const {
    return m_offset;
}

unsigned int SharedString::GetLength() const {
    return m_length;
}

}  // namespace Localization
