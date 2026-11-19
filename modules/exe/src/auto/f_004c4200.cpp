// src: GUESS (confidence: low) [0x005426b0]
struct Slot_005426b0 {
    void (*fn)(void*, void*);
    void* ctx;
    char pad[0x600 - 8];
};
extern int g_Idx_005426b0;
extern Slot_005426b0 g_Slots_005426b0[];
// src: GUESS (confidence: low) [0x005426b0]
void Call_005426b0(void* arg) {
    Slot_005426b0* s = &g_Slots_005426b0[g_Idx_005426b0];
    s->fn(arg, s->ctx);
}
