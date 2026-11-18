// src: GUESS (confidence: low)
class Host_100084d0 {
public:
    virtual void Slot0();
    virtual void Slot1(void* a, void* b);
    // src: GUESS 0x100084d0 (confidence: high)
    bool CallSlot1(void* a, void* b);
};

bool Host_100084d0::CallSlot1(void* a, void* b) {
    Slot1(a, b);
    return true;
}
