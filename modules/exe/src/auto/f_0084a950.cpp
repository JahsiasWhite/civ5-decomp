// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct Vec3_008e49b0 {
    float x, y, z;
};

class Host_008e49b0 {
public:
    char pad[0x60];
    Vec3_008e49b0 m_vec;
    // src: GUESS (confidence: high) [0x008e49b0]
    void __thiscall SetVec(const Vec3_008e49b0* v);
};

void Host_008e49b0::SetVec(const Vec3_008e49b0* v) {
    m_vec.x = v->x;
    m_vec.y = v->y;
    m_vec.z = v->z;
}
