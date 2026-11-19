// src: GUESS (confidence: low) [0x0082cef0]
struct Node_0082cef0 {
    char pad[0x10];
    int unk10;
    char pad2[4];
    void* unk18;
};

// src: GUESS (confidence: low) [0x0082cef0]
struct Out_0082cef0 {
    char pad[4];
    void* unk4;
};

// src: GUESS (confidence: low) [0x0082cef0]
struct Class_0082cef0 {
    char pad[4];
    Node_0082cef0* node;

    bool GetOut(Out_0082cef0* out);
};

bool Class_0082cef0::GetOut(Out_0082cef0* out) {
    Node_0082cef0* n = this->node;
    if (n->unk10 != 0) {
        void* p = n->unk18;
        if (p != 0) {
            out->unk4 = p;
            return true;
        }
    }
    return false;
}
