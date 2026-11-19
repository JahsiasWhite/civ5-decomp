#include <map>

// src: GUESS (confidence: low)
struct TreeVal_006700b0 {
    int m_v;
};

// src: LIB [0x006700b0]
typedef std::map<unsigned int, TreeVal_006700b0> TreeMap_006700b0;

// src: GUESS (confidence: low)
void ForceTreeInc_006700b0(TreeMap_006700b0::const_iterator& it) {
    ++it;
}
