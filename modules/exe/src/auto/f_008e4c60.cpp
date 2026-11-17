// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct Vec3_008e4c60 {
    float x, y, z;
};

class Host_008e4c60 {
public:
    char pad[80];
    float x, y, z;
    // src: GUESS (confidence: high) [0x008e4c60]
    Vec3_008e4c60 __thiscall GetVec() const;
};

Vec3_008e4c60 Host_008e4c60::GetVec() const {
    Vec3_008e4c60 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}
