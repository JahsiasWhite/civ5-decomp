// c5d-model: Gemini 3.8 Flash
struct Node_008f43b0 {
    int pad;
    int flag;
};

class Host_008f43b0 {
public:
    char pad[0x20];
    Node_008f43b0* m_node;
    // src: GUESS (confidence: high) [0x008f43b0]
    int __thiscall Check() const;
};

int Host_008f43b0::Check() const {
    if (m_node && m_node->flag) {
        return 1;
    }
    return 0;
}
