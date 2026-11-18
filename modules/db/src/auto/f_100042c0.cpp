// c5d-cflags: -/EHsc
#include <list>
#include <string>

// src: GUESS (confidence: low)
std::list<std::string>::iterator ForceListErase_100042c0(std::list<std::string>& lst, std::list<std::string>::iterator it) {
    return lst.erase(it);
}
