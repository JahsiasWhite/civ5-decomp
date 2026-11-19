// src: GUESS (confidence: low) [0x00935650]
struct UnkEntry28_00935650 {
    char pad[0x28];
};

extern char g_TableEnd_00935650;

// src: GUESS (confidence: low) [0x00935650]
UnkEntry28_00935650* GetEntryFromEnd_00935650(unsigned int idx) {
    if (idx < 7) {
        return (UnkEntry28_00935650*)(&g_TableEnd_00935650 - idx * sizeof(UnkEntry28_00935650));
    }
    return 0;
}
