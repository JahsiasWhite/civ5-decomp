// c5d-cflags: -/EHsc
#include <list>
#include <string>

// src: GUESS (confidence: low)
struct NodeStr_1000cd10 {
    // src: GUESS (confidence: low)
    std::string value;
};

// src: GUESS (confidence: low)
std::list<NodeStr_1000cd10>::iterator ForceListErase_1000cd10(
    std::list<NodeStr_1000cd10>& lst,
    std::list<NodeStr_1000cd10>::iterator it) {
    return lst.erase(it);
}
