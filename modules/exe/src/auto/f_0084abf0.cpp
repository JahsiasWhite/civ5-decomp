// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct Vec3_008e4c40 {
    float x, y, z;
};

class Host_008e4c40 {
public:
    char pad[96];
    float x, y, z;
    // src: GUESS (confidence: high) [0x008e4c40]
    Vec3_008e4c40 __thiscall GetVec() const;
};

Vec3_008e4c40 Host_008e4c40::GetVec() const {
    Vec3_008e4c40 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}
