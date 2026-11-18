// src: GUESS (confidence: medium) [0x00841470]
#include "Unk_00b89ec8.h"

// src: GUESS (confidence: low)
class UnkChild_00841470 {
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07(float value) = 0;
};

void Unk_00b89ec8::Slot13(int key, float value) {
    UnkChild_00841470* pObj = (UnkChild_00841470*)Lookup(key);
    pObj->Slot07(value);
    Apply((int)pObj);
}
