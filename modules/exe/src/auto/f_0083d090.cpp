// Lazily detects the byte order: 1 for little-endian, 2 for big-endian.

// src: GUESS (confidence: low) [0x00cb0ae4]
extern int g_byteOrder_00cb0ae4;

// src: GUESS (confidence: low) [0x0083d090]
int GetByteOrder_0083d090()
{
    if (g_byteOrder_00cb0ae4 == 0)
    {
        union
        {
            int value;
            unsigned char bytes[4];
        } probe;
        probe.bytes[0] = 1;
        probe.bytes[1] = 0;
        probe.bytes[2] = 0;
        probe.bytes[3] = 0;
        g_byteOrder_00cb0ae4 = (probe.value == 1) ? 1 : 2;
    }
    return g_byteOrder_00cb0ae4;
}
