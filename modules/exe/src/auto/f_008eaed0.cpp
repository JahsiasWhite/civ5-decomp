// src: GUESS (confidence: low) [0x008eaed0]
struct GrannySrcVertex_008eaed0
{
    float Position[3];
    unsigned char BoneWeights[4];
    unsigned char BoneIndices[4];
    float Normal[3];
    float Tangent[3];
};

struct GrannyDstVertex_008eaed0
{
    float Position[3];
    float Normal[3];
    float Tangent[3];
};

struct GrannyMatrix4x4_008eaed0
{
    float M[16];
};

// src: GUESS (confidence: low) [0x05f01c68]
static float g_DeformSum_008eaed0[16];
// src: GUESS (confidence: low) [0x05f01ca8]
static float g_DeformWeight_008eaed0;
// src: GUESS (confidence: low) [0x05f01cac]
static const GrannyMatrix4x4_008eaed0* g_DeformTransform_008eaed0;

#define SCALE_MAT(dst, w, src) \
    dst[0]  = w * src[0];  dst[1]  = w * src[1];  dst[2]  = w * src[2];  dst[3]  = w * src[3]; \
    dst[4]  = w * src[4];  dst[5]  = w * src[5];  dst[6]  = w * src[6];  dst[7]  = w * src[7]; \
    dst[8]  = w * src[8];  dst[9]  = w * src[9];  dst[10] = w * src[10]; dst[11] = w * src[11]; \
    dst[12] = w * src[12]; dst[13] = w * src[13]; dst[14] = w * src[14]; dst[15] = w * src[15];

#define ACCUM_MAT(dst, w, src) \
    dst[0]  += w * src[0];  dst[1]  += w * src[1];  dst[2]  += w * src[2];  dst[3]  += w * src[3]; \
    dst[4]  += w * src[4];  dst[5]  += w * src[5];  dst[6]  += w * src[6];  dst[7]  += w * src[7]; \
    dst[8]  += w * src[8];  dst[9]  += w * src[9];  dst[10] += w * src[10]; dst[11] += w * src[11]; \
    dst[12] += w * src[12]; dst[13] += w * src[13]; dst[14] += w * src[14]; dst[15] += w * src[15];

// src: GUESS (confidence: low) [0x008eaed0]
void DeformPWNG3433D_008eaed0(
    int Count,
    const void* SourceInit,
    void* DestInit,
    const GrannyMatrix4x4_008eaed0* Transforms,
    int CopySize,
    int SourceStride,
    int DestStride)
{
    const unsigned char* Source = (const unsigned char*)SourceInit;
    unsigned char* Dest = (unsigned char*)DestInit;

    while (Count--)
    {
        const GrannySrcVertex_008eaed0* s = (const GrannySrcVertex_008eaed0*)Source;
        GrannyDstVertex_008eaed0* d = (GrannyDstVertex_008eaed0*)Dest;

        g_DeformTransform_008eaed0 = &Transforms[s->BoneIndices[0]];
        g_DeformWeight_008eaed0 = (float)s->BoneWeights[0] * (1.0f / 255.0f);
        SCALE_MAT(g_DeformSum_008eaed0, g_DeformWeight_008eaed0, g_DeformTransform_008eaed0->M);

        g_DeformTransform_008eaed0 = &Transforms[s->BoneIndices[1]];
        g_DeformWeight_008eaed0 = (float)s->BoneWeights[1] * (1.0f / 255.0f);
        ACCUM_MAT(g_DeformSum_008eaed0, g_DeformWeight_008eaed0, g_DeformTransform_008eaed0->M);

        g_DeformTransform_008eaed0 = &Transforms[s->BoneIndices[2]];
        g_DeformWeight_008eaed0 = (float)s->BoneWeights[2] * (1.0f / 255.0f);
        ACCUM_MAT(g_DeformSum_008eaed0, g_DeformWeight_008eaed0, g_DeformTransform_008eaed0->M);

        g_DeformTransform_008eaed0 = &Transforms[s->BoneIndices[3]];
        g_DeformWeight_008eaed0 = (float)s->BoneWeights[3] * (1.0f / 255.0f);
        ACCUM_MAT(g_DeformSum_008eaed0, g_DeformWeight_008eaed0, g_DeformTransform_008eaed0->M);

        d->Position[0] = s->Position[2] * g_DeformSum_008eaed0[8]  + s->Position[1] * g_DeformSum_008eaed0[4] + s->Position[0] * g_DeformSum_008eaed0[0] + g_DeformSum_008eaed0[12];
        d->Position[1] = s->Position[2] * g_DeformSum_008eaed0[9]  + s->Position[1] * g_DeformSum_008eaed0[5] + s->Position[0] * g_DeformSum_008eaed0[1] + g_DeformSum_008eaed0[13];
        d->Position[2] = s->Position[2] * g_DeformSum_008eaed0[10] + s->Position[1] * g_DeformSum_008eaed0[6] + s->Position[0] * g_DeformSum_008eaed0[2] + g_DeformSum_008eaed0[14];

        d->Normal[0] = s->Normal[2] * g_DeformSum_008eaed0[8]  + s->Normal[1] * g_DeformSum_008eaed0[4] + s->Normal[0] * g_DeformSum_008eaed0[0];
        d->Normal[1] = s->Normal[2] * g_DeformSum_008eaed0[9]  + s->Normal[1] * g_DeformSum_008eaed0[5] + s->Normal[0] * g_DeformSum_008eaed0[1];
        d->Normal[2] = s->Normal[2] * g_DeformSum_008eaed0[10] + s->Normal[1] * g_DeformSum_008eaed0[6] + s->Normal[0] * g_DeformSum_008eaed0[2];

        d->Tangent[0] = s->Tangent[2] * g_DeformSum_008eaed0[8]  + s->Tangent[1] * g_DeformSum_008eaed0[4] + s->Tangent[0] * g_DeformSum_008eaed0[0];
        d->Tangent[1] = s->Tangent[2] * g_DeformSum_008eaed0[9]  + s->Tangent[1] * g_DeformSum_008eaed0[5] + s->Tangent[0] * g_DeformSum_008eaed0[1];
        d->Tangent[2] = s->Tangent[2] * g_DeformSum_008eaed0[10] + s->Tangent[1] * g_DeformSum_008eaed0[6] + s->Tangent[0] * g_DeformSum_008eaed0[2];

        const unsigned int* pSrcTail = (const unsigned int*)(s + 1);
        unsigned int* pDstTail = (unsigned int*)(d + 1);
        int i = CopySize;
        while (i--)
        {
            *pDstTail++ = *pSrcTail++;
        }

        Source += SourceStride;
        Dest += DestStride;
    }
}
