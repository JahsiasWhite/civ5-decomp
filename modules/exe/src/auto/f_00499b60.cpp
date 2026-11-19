// Empties the object's byte vector.

#include <vector>

// src: GUESS (confidence: low)
class ByteBuffer_005a40e0
{
public:
    // src: GUESS (confidence: low) [0x005a40e0]
    void Clear();

    // src: GUESS (confidence: low)
    std::vector<char> m_bytes;
};

void ByteBuffer_005a40e0::Clear()
{
    m_bytes.clear();
}
