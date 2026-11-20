extern "C" void* __stdcall D3DXMatrixTranslation(void* pOut, float x, float y, float z);

// src: GUESS (confidence: low)
struct Vec3_00664080
{
    float x, y, z;
};

// src: GUESS (confidence: high) [0x00664080]
void* MatrixTranslation_00664080(void* pOut, const Vec3_00664080* v)
{
    return D3DXMatrixTranslation(pOut, v->x, v->y, v->z);
}
