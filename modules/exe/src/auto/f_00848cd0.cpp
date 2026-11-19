// Sets a 4x4 float matrix to the identity.

#include <string.h>

extern "C" float g_float_009f72f4;

// src: GUESS (confidence: low)
struct Matrix4_008e2c40
{
    float m[4][4];
};

// src: GUESS (confidence: low) [0x008e2c40]
void SetIdentity_008e2c40(Matrix4_008e2c40* matrix)
{
    memset(matrix, 0, sizeof(*matrix));
    matrix->m[0][0] = g_float_009f72f4;
    matrix->m[1][1] = g_float_009f72f4;
    matrix->m[2][2] = g_float_009f72f4;
    matrix->m[3][3] = g_float_009f72f4;
}
