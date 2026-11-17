// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct Block_0073f030 {
    short data[0xc1];
};

class Host_0073f030 {
public:
    char pad[0xc400e4];
    Block_0073f030 m_block;
    // src: GUESS (confidence: high) [0x0073f030]
    void __thiscall SetBlock(const Block_0073f030* src);
};

void __thiscall Host_0073f030::SetBlock(const Block_0073f030* src) {
    m_block = *src;
}
