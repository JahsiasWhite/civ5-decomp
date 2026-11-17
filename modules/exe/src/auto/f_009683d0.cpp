// c5d-model: Gemini 3.8 Flash
struct Node_009683d0 {
    int val;
    int flag;
};

// src: GUESS (confidence: high) [0x009683d0]
int __cdecl CheckNode_009683d0(Node_009683d0* node) {
    if (node->flag != 0 || node->val == 5) {
        return node->val;
    }
    return 0;
}
