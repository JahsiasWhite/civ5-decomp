// src: GUESS (confidence: low) [0x00583620]
struct Slot_00583620 {
    void (*fn)(void*, void*);
    void* ctx;
    char pad[0x600 - 8];
};
extern int g_Idx_00583620;
extern Slot_00583620 g_Slots_00583620[];
// src: GUESS (confidence: low) [0x00583620]
void Call_00583620(void* arg) {
    Slot_00583620* s = &g_Slots_00583620[g_Idx_00583620];
    s->fn(arg, s->ctx);
}
