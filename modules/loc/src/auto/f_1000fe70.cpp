// src: EXE [0x1000fe70]

// src: GUESS (confidence: low)
struct CleanupNode_1000fe70 {
    virtual void Slot0() {}
    virtual void Slot1() {}
    virtual void Release(int arg) {}
    void Destroy();
};

// src: GUESS (confidence: low)
void CleanupNode_1000fe70::Destroy() {
    Release(0);
    ::operator delete(this);
}
