// src: GUESS (confidence: low) [0x009b42f0]
struct VTable_009b42f0 {
    char pad[0x20];
    bool (*fn20)(void*);
};
// src: GUESS (confidence: low) [0x009b42f0]
struct Node_009b42f0 {
    char pad[8];
    Node_009b42f0* f8;
    char pad2[0x18 - 0xc];
    VTable_009b42f0* f18;
    bool Check();
};
bool Node_009b42f0::Check() {
    Node_009b42f0* n = this->f8;
    if (this != n && this == n->f8) {
        bool (*fn)(void*) = n->f18->fn20;
        if (fn != 0) {
            return fn(n);
        }
    }
    return false;
}
