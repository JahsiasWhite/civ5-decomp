// src: GUESS (confidence: high)
struct Item16_008eb210 {
    char data[16];
};

// src: GUESS (confidence: high)
struct Vec16_008eb210 {
    int pad0;
    Item16_008eb210* m_first;
    Item16_008eb210* m_last;
    int size() const { return (int)(m_last - m_first); }
};

// src: GUESS (confidence: high)
struct Sub_008eb210 {
    char pad0[0x4c];
    Vec16_008eb210 m_vec;
};

class Host_008eb210 {
public:
    char pad0[0x48];
    int m_base;
    char pad1[0x10];
    Sub_008eb210* m_sub;
    // src: GUESS (confidence: high) [0x008eb210]
    int __thiscall CalcValue() const;
};

int __thiscall Host_008eb210::CalcValue() const {
    return m_sub->m_vec.size() * 16 + m_base;
}
