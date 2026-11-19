// src: GUESS (confidence: low) [0x00980350]
extern void* g_Table_00980350[];
extern void* g_Default_00980350;

// src: GUESS (confidence: low) [0x00980350]
void* Lookup_00980350(unsigned int val) {
    if (val == 0x102 || val == 0x10a) {
        val &= ~0x100;
    }
    if (val <= 0x1e) {
        return g_Table_00980350[val];
    }
    return &g_Default_00980350;
}
