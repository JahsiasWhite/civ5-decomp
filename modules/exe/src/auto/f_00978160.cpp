// c5d-model: Gemini 3.8 Flash
struct Node_00978160 {
    int pad;
    Node_00978160* next;
};
// src: GUESS (confidence: high) [0x00978160]
Node_00978160* __cdecl GetNext_00978160(Node_00978160* p) {
    if (!p) return p;
    return p->next;
}
