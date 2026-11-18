// src: GUESS (confidence: medium) [0x100055b0]
// c5d-cflags: -/EHsc -/D_HAS_EXCEPTIONS=0 +/D_HAS_EXCEPTIONS=1
#include <exception>

// src: GUESS (confidence: low)
class Unk_1008af5c : public std::exception {
public:
    virtual ~Unk_1008af5c() {}
};

// src: GUESS (confidence: low)
Unk_1008af5c* CreateUnk_100055b0() {
    return new Unk_1008af5c();
}
