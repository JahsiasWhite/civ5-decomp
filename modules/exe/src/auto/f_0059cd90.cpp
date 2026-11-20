#include <algorithm>

// src: GUESS (confidence: low)
struct Elem4_0059cd90
{
    int m_v;
};

// src: LIB [0x0059cd90]
Elem4_0059cd90* CopyBackward_0059cd90(Elem4_0059cd90* first, Elem4_0059cd90* last, Elem4_0059cd90* dest)
{
    return std::copy_backward(first, last, dest);
}
