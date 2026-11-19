// src: GUESS (confidence: low) [0x004b8750]
struct Vec3_004b8750 {
    float x, y, z;
};
// src: GUESS (confidence: low) [0x004b8750]
struct Class_004b8750 {
    char pad[0x84];
    float x, y, z;
    Vec3_004b8750 GetPos();
};
Vec3_004b8750 Class_004b8750::GetPos() {
    Vec3_004b8750 out;
    out.x = this->x;
    out.y = this->y;
    out.z = this->z;
    return out;
}
