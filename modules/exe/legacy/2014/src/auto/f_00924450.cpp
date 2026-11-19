// MD5 initialisation: the standard starting state and a zero bit count.

// src: GUESS (confidence: medium)
struct MD5Context_00924450
{
    // src: GUESS (confidence: medium)
    unsigned int state[4];
    // src: GUESS (confidence: medium)
    unsigned int count[2];
};

// src: GUESS (confidence: medium) [0x00924450]
void MD5Init_00924450(MD5Context_00924450* context)
{
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
    context->count[0] = 0;
    context->count[1] = 0;
}
