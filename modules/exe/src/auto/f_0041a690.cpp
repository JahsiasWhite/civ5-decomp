// c5d-cflags: +/Oy-
#include <string.h>

// src: GUESS (confidence: high) [0x0041a690]
struct Obj_0041a690 {
    unsigned char pad[0x20];
    unsigned char buf[0x2618];
    int val;
    bool ready;

    void init(const int* data, bool flag);
};

// src: GUESS (confidence: high) [0x0041a690]
void Obj_0041a690::init(const int* data, bool flag) {
    if (!flag && data) {
        memcpy(buf, data, sizeof(buf));
        val = *data;
        ready = true;
    } else {
        val = 0x25;
        ready = true;
    }
}
