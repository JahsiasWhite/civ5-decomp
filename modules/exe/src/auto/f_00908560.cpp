#include <vector>

// src: GUESS (confidence: low)
struct Unk_00908560;

// src: LIB [0x00908560]
typedef std::vector<Unk_00908560*> PtrVec_00908560;

// src: GUESS (confidence: low)
PtrVec_00908560::iterator ForceVecErase_00908560(PtrVec_00908560& v, PtrVec_00908560::const_iterator first, PtrVec_00908560::const_iterator last) {
    return v.erase(first, last);
}
