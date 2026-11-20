#include <algorithm>

// src: GUESS (confidence: low)
struct Elem4_004786e0
{
    int m_v;
};

// src: LIB [0x004786e0]
Elem4_004786e0* CopyBackward_004786e0(Elem4_004786e0* first, Elem4_004786e0* last, Elem4_004786e0* dest)
{
    return std::copy_backward(first, last, dest);
}
