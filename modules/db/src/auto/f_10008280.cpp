// src: GUESS (confidence: low)
class Host_10008280 {
public:
    virtual void Slot0(void* a, void* b);
    // src: GUESS 0x10008280 (confidence: high)
    bool CallSlot0(void* a, void* b);
};

bool Host_10008280::CallSlot0(void* a, void* b) {
    Slot0(a, b);
    return true;
}
