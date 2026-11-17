// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct Vec3_008e5150 {
    float x, y, z;
};

class Host_008e5150 {
public:
    char pad[64];
    float x, y, z;
    // src: GUESS (confidence: high) [0x008e5150]
    Vec3_008e5150 __thiscall GetVec() const;
};

Vec3_008e5150 Host_008e5150::GetVec() const {
    Vec3_008e5150 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}
