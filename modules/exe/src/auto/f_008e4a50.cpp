// c5d-cflags: -/arch:SSE2
// Copies the xyz of one of the object's 16-byte points into `out`.

// src: GUESS (confidence: low)
struct Vec3_008e4a50
{
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low)
struct Point_008e4a50
{
    float x;
    float y;
    float z;
    float w;
};

// src: GUESS (confidence: low)
class PointSet_008e4a50
{
public:
    // src: GUESS (confidence: low) [0x008e4a50]
    void GetPoint(Vec3_008e4a50& out, int index) const;

    char m_pad0[0x30];
    // src: GUESS (confidence: low)
    Point_008e4a50 m_points[1];
};

void PointSet_008e4a50::GetPoint(Vec3_008e4a50& out, int index) const
{
    out.x = m_points[index].x;
    out.y = m_points[index].y;
    out.z = m_points[index].z;
}
