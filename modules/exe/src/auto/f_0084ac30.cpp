// src: GUESS (confidence: medium) [0x008e4c80]
// src: GUESS (confidence: low)
struct Vec3_008e4c80 {
    Vec3_008e4c80(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low)
class Host_008e4c80 {
public:
    char m_pad00[0x50];
    // src: GUESS (confidence: medium)
    float m_x;
    float m_y;
    float m_z;

    // src: GUESS (confidence: medium) [0x008e4c80]
    Vec3_008e4c80 GetNegated() const;
};

Vec3_008e4c80 Host_008e4c80::GetNegated() const {
    return Vec3_008e4c80(-m_x, -m_y, -m_z);
}
