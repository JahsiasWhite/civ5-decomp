// Empties the object's vector of 8-byte pairs.

#include <vector>

// src: GUESS (confidence: low)
struct Pair_008e8ef0
{
    int first;
    int second;
};

// src: GUESS (confidence: low)
class PairList_008e8ef0
{
public:
    // src: GUESS (confidence: low) [0x008e8ef0]
    void Clear();

    // src: GUESS (confidence: low)
    std::vector<Pair_008e8ef0> m_pairs;
};

void PairList_008e8ef0::Clear()
{
    m_pairs.clear();
}
