// FireWorks' serialization stream. Values go out through its third virtual slot
// (size, data); integers are byte-swapped first when the stream's byte order differs
// from the machine's.
#pragma once

#include <windows.h>
#include <vector>
#include "FStringA.h"

// src: GUESS (confidence: medium)
class FDataStream
{
public:
    // Class_0082b530::CallSlot (src/auto/f_0082b530.cpp) under the name this class gives it.
    // src: GUESS (confidence: high) [0x0082b530]
    void operator<<(const char& cValue);
    // src: GUESS (confidence: high) [0x0082b8a0]
    void operator<<(const unsigned int& uiValue);
    // src: GUESS (confidence: high) [0x0082b550]
    void operator<<(const FStringA& strValue);
};

// src: GUESS (confidence: high) [0x00781970]
FDataStream& operator<<(FDataStream& kStream, const bool& bValue);
// src: GUESS (confidence: high) [0x00830500]
FDataStream& operator<<(FDataStream& kStream, const GUID& kGuid);

// The size as an unsigned int, then each element.
template <class T>
inline FDataStream& operator<<(FDataStream& kStream, const std::vector<T>& kVector)
{
    unsigned int uiSize = kVector.size();
    kStream << uiSize;
    typename std::vector<T>::const_iterator itEnd = kVector.end();
    for (typename std::vector<T>::const_iterator it = kVector.begin(); it != itEnd; ++it)
        kStream << *it;
    return kStream;
}
