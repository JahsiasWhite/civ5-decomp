#include <map>

// src: GUESS (confidence: low)
struct TreeVal_00414b40 {
    int m_v;
};

// src: LIB [0x00414b40]
typedef std::map<unsigned int, TreeVal_00414b40> TreeMap_00414b40;

// src: GUESS (confidence: low)
void ForceTreeDec_00414b40(TreeMap_00414b40::const_iterator& it) {
    --it;
}
