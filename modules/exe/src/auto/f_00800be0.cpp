// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

extern "C" void* memset(void* dst, int val, unsigned int size);
extern "C" char* strcpy(char* dst, const char* src);

// src: EXE [0x00894640]
void UnkFn_00894640(void);
// src: EXE [0x00894970]
void UnkFn_00894970(void);
// src: EXE [0x00895700]
void UnkFn_00895700(void);
// src: EXE [0x00895b00]
void UnkFn_00895b00(void);
// src: EXE [0x0089e9d0]
void UnkFn_0089e9d0(void);
// src: EXE [0x0089eaf0]
void UnkFn_0089eaf0(void);
// src: EXE [0x0089f210]
void UnkFn_0089f210(void);
// src: EXE [0x0089f300]
void UnkFn_0089f300(void);
// src: EXE [0x0089f780]
void UnkFn_0089f780(void);
// src: EXE [0x008a1a00]
void UnkFn_008a1a00(void);

#define COPY16(d, s) \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s); ++(d); ++(s); \
    *(d) = *(s);

#define IDENTITY16(d) \
    *(d) = 1.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 1.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 1.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 0.0f; ++(d); \
    *(d) = 1.0f;

// src: GUESS (confidence: low)
struct EmitterDesc_0089ab50
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x68];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
    // src: GUESS (confidence: low)
    unsigned char m_pad6c[0x128];
    // src: GUESS (confidence: low)
    int m_field194;
};

// src: GUESS (confidence: low)
struct Emitter_0089ab50
{
    // src: GUESS (confidence: low)
    char m_name[0x100];
    // src: GUESS (confidence: low)
    int m_field100;
    // src: GUESS (confidence: low)
    int m_field104;
    // src: GUESS (confidence: low)
    float m_field108;
    // src: GUESS (confidence: low)
    float m_field10c;
    // src: GUESS (confidence: low)
    float m_mat110[16];
    // src: GUESS (confidence: low)
    int m_pad150[3];
    // src: GUESS (confidence: low)
    int m_field15c;
    // src: GUESS (confidence: low)
    int m_pad160;
    // src: GUESS (confidence: low)
    EmitterDesc_0089ab50* m_desc;
    // src: GUESS (confidence: low)
    int m_field168;
    // src: GUESS (confidence: low)
    unsigned char m_buf16c[0x100];
    // src: GUESS (confidence: low)
    int m_pad26c;
    // src: GUESS (confidence: low)
    void (*m_fn270)(void);
    // src: GUESS (confidence: low)
    void* m_field274;
    // src: GUESS (confidence: low)
    void (*m_fn278)(void);
    // src: GUESS (confidence: low)
    void* m_field27c;
    // src: GUESS (confidence: low)
    void* m_field280;
    // src: GUESS (confidence: low)
    void (*m_fn284)(void);
    // src: GUESS (confidence: low)
    void (*m_fn288)(void);
    // src: GUESS (confidence: low)
    int m_pad28c;
    // src: GUESS (confidence: low)
    void (*m_fn290)(void);
    // src: GUESS (confidence: low)
    void (*m_fn294)(void);
    // src: GUESS (confidence: low)
    void (*m_fn298)(void);
    // src: GUESS (confidence: low)
    void* m_field29c;
    // src: GUESS (confidence: low)
    int m_field2a0;
    // src: GUESS (confidence: low)
    float m_field2a4;
    // src: GUESS (confidence: low)
    float m_field2a8;
    // src: GUESS (confidence: low)
    int m_field2ac;
    // src: GUESS (confidence: low)
    int m_field2b0;
    // src: GUESS (confidence: low)
    int m_pad2b4;
    // src: GUESS (confidence: low)
    int m_field2b8;
    // src: GUESS (confidence: low)
    float m_field2bc;
    // src: GUESS (confidence: low)
    int m_pad2c0;
    // src: GUESS (confidence: low)
    float m_mat2c4[16];
    // src: GUESS (confidence: low)
    int m_pad304;
    // src: GUESS (confidence: low)
    float m_field308;
    // src: GUESS (confidence: low)
    float m_field30c;
    // src: GUESS (confidence: low)
    float m_field310;
    // src: GUESS (confidence: low)
    float m_field314;
    // src: GUESS (confidence: low)
    float m_field318;
    // src: GUESS (confidence: low)
    int m_field31c;
    // src: GUESS (confidence: low)
    int m_pad320;
    // src: GUESS (confidence: low)
    float m_field324;
    // src: GUESS (confidence: low)
    void (*m_fn328)(void);
    // src: GUESS (confidence: low)
    EmitterDesc_0089ab50* m_desc32c;
    // src: GUESS (confidence: low)
    float m_field330;
    // src: GUESS (confidence: low)
    float m_field334;
    // src: GUESS (confidence: low)
    float m_field338;
    // src: GUESS (confidence: low)
    float m_field33c;
    // src: GUESS (confidence: low)
    float m_field340;
    // src: GUESS (confidence: low)
    float m_field344;
    // src: GUESS (confidence: low)
    float m_field348;
    // src: GUESS (confidence: low)
    float m_field34c;
    // src: GUESS (confidence: low)
    float m_field350;
    // src: GUESS (confidence: low)
    int m_field354;
    // src: GUESS (confidence: low)
    int m_field358;
};

// src: GUESS (confidence: medium) [0x0089ab50]
void InitEmitter_0089ab50(Emitter_0089ab50* obj, const float* mat, EmitterDesc_0089ab50* desc, const char* name)
{
    obj->m_field324 = 0.0f;
    obj->m_field108 = 0.0f;
    obj->m_field10c = 0.0f;
    obj->m_field15c = 0;

    if (mat)
    {
        float* a1 = obj->m_mat110;
        const float* a5 = mat;
        COPY16(a1, a5);
    }
    else
    {
        float* a4 = obj->m_mat110;
        IDENTITY16(a4);
    }

    {
        float* a3 = obj->m_mat2c4;
        const float* a2 = obj->m_mat110;
        COPY16(a3, a2);
    }

    obj->m_field168 = 0;
    obj->m_field31c = 0;
    obj->m_field358 = 0;
    obj->m_field354 = 0;
    obj->m_desc = desc;
    obj->m_desc32c = desc;
    obj->m_field2a8 = 0.0f;
    obj->m_field2a4 = 0.0f;
    obj->m_field2bc = 0.0f;
    obj->m_field330 = 1.0f;
    obj->m_field334 = 1.0f;
    obj->m_field338 = 1.0f;
    obj->m_field33c = 1.0f;
    obj->m_field340 = 1.0f;
    obj->m_field344 = 0.0f;
    obj->m_field348 = 0.1f;
    obj->m_field34c = 0.0f;
    obj->m_field350 = 0.0f;
    obj->m_field308 = 0.0f;
    obj->m_field30c = 1.0f;
    obj->m_field314 = 0.0f;
    obj->m_field310 = 0.0f;
    obj->m_field318 = 0.0f;
    memset(obj->m_buf16c, 0, 0x100);
    obj->m_field2a0 = 0;
    obj->m_fn270 = UnkFn_00894640;
    obj->m_fn284 = UnkFn_008a1a00;
    obj->m_field280 = 0;
    obj->m_field274 = 0;
    obj->m_fn278 = UnkFn_00894970;
    obj->m_fn288 = UnkFn_00895b00;
    obj->m_fn294 = 0;
    obj->m_fn290 = 0;
    obj->m_fn298 = 0;
    obj->m_field2ac = 0;
    obj->m_field2b0 = 0;
    obj->m_field2b8 = 0;
    obj->m_field27c = 0;
    obj->m_field29c = 0;
    obj->m_fn328 = UnkFn_00895700;

    if (desc->m_field194 > 0)
    {
        obj->m_fn294 = UnkFn_0089e9d0;
        obj->m_fn290 = UnkFn_0089eaf0;
        obj->m_fn298 = UnkFn_0089f210;
    }

    if (obj->m_desc->m_flags & 0x200)
    {
        obj->m_fn288 = UnkFn_0089f300;
    }
    else if (obj->m_desc->m_flags & 0x8000)
    {
        obj->m_fn284 = UnkFn_0089f780;
    }
    else if (obj->m_desc->m_flags & 0x100)
    {
        obj->m_fn288 = UnkFn_0089f300;
    }

    strcpy(obj->m_name, name);
    obj->m_field100 = 0x306;
}
