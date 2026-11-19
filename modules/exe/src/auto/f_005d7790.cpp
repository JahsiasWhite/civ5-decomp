// src: GUESS (confidence: low) [0x0053c4c0]
struct Slot_0053c4c0 {
    void (*fn)(void*, void*);
    void* ctx;
    char pad[0x600 - 8];
};
extern int g_Idx_0053c4c0;
extern Slot_0053c4c0 g_Slots_0053c4c0[];
// src: GUESS (confidence: low) [0x0053c4c0]
void Call_0053c4c0(void* arg) {
    Slot_0053c4c0* s = &g_Slots_0053c4c0[g_Idx_0053c4c0];
    s->fn(arg, s->ctx);
}
