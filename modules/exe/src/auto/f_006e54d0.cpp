// src: GUESS (confidence: low) [0x006e54d0]
struct Class_006e54d0 {
    char pad[0x98];
    unsigned int flags;
    void SetFlag(bool enable);
};
void Class_006e54d0::SetFlag(bool enable) {
    if (enable) {
        this->flags |= 0x2000;
    } else {
        this->flags &= ~0x2000;
    }
}
