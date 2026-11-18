// src: GUESS (confidence: medium) [0x008e4a10]
// src: GUESS (confidence: low)
struct Vec3_008e4a10 {
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low)
class Host_008e4a10 {
public:
    char m_pad00[0x50];
    // src: GUESS (confidence: medium)
    Vec3_008e4a10 m_vPos;  // +0x50

    // src: GUESS (confidence: medium) [0x008e4a10]
    void GetNegated(Vec3_008e4a10& rOut) const;
};

void Host_008e4a10::GetNegated(Vec3_008e4a10& rOut) const {
    rOut.x = -m_vPos.x;
    rOut.y = -m_vPos.y;
    rOut.z = -m_vPos.z;
}
