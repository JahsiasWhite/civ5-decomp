// c5d-cflags: -/Ob1 +/Ob0
// src: GUESS (confidence: low) [0x006c8f80]
#include <string>

struct Auto_006c8f80 : std::string {
    int f_006c8f80(); // src: GUESS (confidence: low) [0x006c8f80]
};

int Auto_006c8f80::f_006c8f80() {
    if (empty() || c_str() == 0) {
        return 1;
    }
    return 0;
}
