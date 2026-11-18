// c5d-cflags: -/EHsc
#include <vector>

// src: GUESS (confidence: low)
struct Elem_10004990 {
    // src: GUESS (confidence: low)
    Elem_10004990& operator=(const Elem_10004990& o) {
        value = o.value;
        return *this;
    }
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS (confidence: low)
std::vector<Elem_10004990>::iterator ForceErase_10004990(
    std::vector<Elem_10004990>& v,
    std::vector<Elem_10004990>::iterator a,
    std::vector<Elem_10004990>::iterator b) {
    return v.erase(a, b);
}
