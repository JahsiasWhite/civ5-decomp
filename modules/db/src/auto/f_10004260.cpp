// c5d-cflags: -/EHsc
#include <list>
#include <string>

// src: GUESS (confidence: low)
struct NodeStr_10004260 {
    // src: GUESS (confidence: low)
    std::string value;
};

// src: GUESS (confidence: low)
std::list<NodeStr_10004260>::iterator ForceListErase_10004260(
    std::list<NodeStr_10004260>& lst,
    std::list<NodeStr_10004260>::iterator it) {
    return lst.erase(it);
}
