// c5d-cflags: +/GS-   (no buffer-security copy of the by-value array parameter)
// Stores a by-value settings block (0x182 bytes) into the object. The first
// argument isn't used.

// src: GUESS (confidence: low)
struct Block_00415e00
{
    unsigned short words[0xc1];
};

// src: GUESS (confidence: low)
class Owner_00415e00
{
public:
    // src: GUESS (confidence: low) [0x00415e00]
    void SetBlock(int unused, Block_00415e00 block);

    char m_pad0[0x5d00];
    // src: GUESS (confidence: low)
    Block_00415e00 m_block;
};

void Owner_00415e00::SetBlock(int unused, Block_00415e00 block)
{
    m_block = block;
}
