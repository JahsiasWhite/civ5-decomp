// Copies [first, last) of strings backwards so that it ends at destEnd;
// returns the start of the copy.

#include <string>
#include <algorithm>

// src: GUESS (confidence: low) [0x006c00a0]
std::string* CopyStringsBackward_006c00a0(std::string* first, std::string* last, std::string* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
