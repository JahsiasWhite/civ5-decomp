// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct Vec3_008e49d0 {
    float x, y, z;
};

class Host_008e49d0 {
public:
    char pad[96];
    float x, y, z;
    // src: GUESS (confidence: high) [0x008e49d0]
    void __thiscall GetVec(Vec3_008e49d0* out) const;
};

void Host_008e49d0::GetVec(Vec3_008e49d0* out) const {
    out->x = x;
    out->y = y;
    out->z = z;
}
