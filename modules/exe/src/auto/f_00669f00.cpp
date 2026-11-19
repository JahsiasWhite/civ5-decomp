#include <map>

// src: GUESS (confidence: low)
struct TreeVal_00426bb0 {
    int m_v;
};

// src: LIB [0x00426bb0]
typedef std::map<unsigned int, TreeVal_00426bb0> TreeMap_00426bb0;

// src: GUESS (confidence: low)
TreeMap_00426bb0::const_iterator ForceTreeFind_00426bb0(const TreeMap_00426bb0& m, const unsigned int& k) {
    return m.find(k);
}
