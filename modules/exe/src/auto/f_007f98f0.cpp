// c5d-cflags: +/Od -/arch:SSE2
// Copies a 3-component vector into three globals.

// src: GUESS (confidence: low)
struct Vec3_00893860
{
    float x;
    float y;
    float z;
};

// src: GUESS (confidence: low) [0x00c9ec9c]
extern float g_x_00c9ec9c;
// src: GUESS (confidence: low) [0x00c9eca0]
extern float g_y_00c9eca0;
// src: GUESS (confidence: low) [0x00c9eca4]
extern float g_z_00c9eca4;

// src: GUESS (confidence: low) [0x00893860]
void SetGlobalVec(const Vec3_00893860* v)
{
    g_x_00c9ec9c = v->x;
    g_y_00c9eca0 = v->y;
    g_z_00c9eca4 = v->z;
}
