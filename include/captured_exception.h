#pragma once
// c5d-vtable: 0x00b82580
#include <exception>

namespace tbb {

// src: EXE [0x00b82580]
class captured_exception : public stdext::exception {
public:
    // src: EXE [0x007bc440]
    virtual ~captured_exception();

    // src: GUESS (confidence: low)
    int m_i08;            // +0x08
    // src: GUESS (confidence: high)
    char* m_szName_0c;    // +0x0c
    // src: GUESS (confidence: high)
    char* m_szReason_10;  // +0x10
};

}  // namespace tbb
