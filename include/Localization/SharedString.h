// Localization::SharedString: an immutable piece of a string buffer that several
// instances share. Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "LocalizationAPI.h"
#include <memory>

namespace Localization {

class CVLOCALIZATION_API SharedString {
    friend class String;
public:
    // src: EXE [0x10007000]
    SharedString();
    // user-written in the DLL (they copy the shared buffer pointer); declared here so
    // the exported class doesn't get compiler-generated ones
    SharedString(const SharedString& copy);
    SharedString& operator=(const SharedString& other);
    // src: EXE [0x10001000]
    ~SharedString();

    // src: EXE [0x10007130]
    const char* GetBuffer(unsigned int& ruiBufferLength) const;
    // src: EXE [0x10007140]
    const char* GetString(unsigned int& ruiLength) const;
    unsigned int GetBufferLength() const;
    unsigned int GetOffset() const;
    unsigned int GetLength() const;
    // src: EXE [0x10007160]
    bool SetOffsetAndLength(unsigned int uiOffset, unsigned int uiLength);
    // src: EXE [0x100070f0]
    bool operator==(const SharedString& kOther) const;

private:
    // src: GUESS (confidence: high)
    std::tr1::shared_ptr<const char> m_spBuffer;  // +0x00 (+0x04 rep)
    unsigned int m_BufferLength;                  // +0x08
    unsigned int m_offset;                        // +0x0c
    unsigned int m_length;                        // +0x10
};

}  // namespace Localization
