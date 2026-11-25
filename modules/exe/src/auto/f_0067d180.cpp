// src: GUESS (confidence: low) [0x0067d180]
struct GlobalCtx67 {
    unsigned char pad0[0xa4];
    void* mgr;
};

// src: GUESS (confidence: low) [0x00b49338]
GlobalCtx67* g_pGlobalCtx67;

// src: GUESS (confidence: low) [0x008210f6]
extern "C" void* __stdcall AcquireSlot67(void* mgr);
// src: GUESS (confidence: low) [0x008210f0]
extern "C" void __stdcall SetSlotFlag67(void* slot, int flag);
// src: GUESS (confidence: low) [0x008210ea]
extern "C" void __stdcall CommitSlot67(void* mgr, void* slot);

struct Obj67 {
    unsigned char pad0[0x9808];
    unsigned char f9808;
    unsigned char f9809;

    void __thiscall UpdateFlag();
};

void __thiscall Obj67::UpdateFlag() {
    if (f9808 && f9809) {
        void* mgr = g_pGlobalCtx67->mgr;
        void* slot = AcquireSlot67(mgr);
        if (slot) {
            SetSlotFlag67(slot, 1);
            CommitSlot67(mgr, slot);
        }
    } else {
        void* mgr = g_pGlobalCtx67->mgr;
        void* slot = AcquireSlot67(mgr);
        if (slot) {
            SetSlotFlag67(slot, 0);
            CommitSlot67(mgr, slot);
        }
    }
}
