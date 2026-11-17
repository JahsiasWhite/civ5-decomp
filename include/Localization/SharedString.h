// Localization::SharedString: an immutable piece of a string buffer that several
// instances share. Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "LocalizationAPI.h"

namespace Localization {

class CVLOCALIZATION_API SharedString {
public:
    // user-written in the DLL (they copy the shared buffer pointer); declared here so
    // the exported class doesn't get compiler-generated ones
    SharedString(const SharedString& copy);
    SharedString& operator=(const SharedString& other);

    unsigned int GetBufferLength() const;
    unsigned int GetOffset() const;
    unsigned int GetLength() const;

private:
    void* m_Buffer[2];                 // +0x00 shared pointer to the buffer (object, count)
    unsigned int m_BufferLength;       // +0x08
    unsigned int m_offset;             // +0x0c
    unsigned int m_length;             // +0x10
};

}  // namespace Localization
