// src: GUESS (confidence: low)
struct F0044d9e0In {
    unsigned int x;
    unsigned int y;
};

struct F0044d9e0Out {
    float x;
    float y;
};

struct F0044d9e0 {
    unsigned char pad0[0x74];
    unsigned int height;

    void __thiscall f_0044d9e0(const F0044d9e0In* in, F0044d9e0Out* out);
};

void __thiscall F0044d9e0::f_0044d9e0(const F0044d9e0In* in, F0044d9e0Out* out) {
    out->x = in->x * 222.0f + 128.0f;
    out->y = (height - in->y) * 192.0f + 128.0f;
    if (in->y & 1) {
        out->x += 111.0f;
    }
}
