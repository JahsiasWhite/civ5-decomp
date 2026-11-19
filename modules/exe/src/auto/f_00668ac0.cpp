// src: GUESS (confidence: low) [0x006726b0]
struct Slot_006726b0 {
    void (*fn)(void*, void*);
    void* ctx;
    char pad[0x600 - 8];
};
extern int g_Idx_006726b0;
extern Slot_006726b0 g_Slots_006726b0[];
// src: GUESS (confidence: low) [0x006726b0]
void Call_006726b0(void* arg) {
    Slot_006726b0* s = &g_Slots_006726b0[g_Idx_006726b0];
    s->fn(arg, s->ctx);
}
