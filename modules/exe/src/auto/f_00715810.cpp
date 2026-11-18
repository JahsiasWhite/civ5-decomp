#include <map>

// src: GUESS (confidence: low)
struct TreeVal_00715810 {
    int m_v;
};

// src: LIB [0x00715810]
typedef std::map<unsigned int, TreeVal_00715810> TreeMap_00715810;

// src: GUESS (confidence: low)
TreeMap_00715810::iterator ForceTreeRrotate_00715810(TreeMap_00715810& m, TreeMap_00715810::const_iterator it) {
    return m.erase(it);
}
