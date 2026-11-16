// c5d-model: Gemini 3.8 Flash
struct Node_00834ff0 {
    int pad;
    int val;
};

class Host_00834ff0 {
public:
    char pad1[0x22c];
    int m_fallback;
    char pad2[0xc];
    Node_00834ff0* m_node;
    // src: GUESS (confidence: high) [0x00834ff0]
    int __thiscall GetValue() const;
};

int Host_00834ff0::GetValue() const {
    if (m_node) {
        return m_node->val;
    }
    return m_fallback;
}
