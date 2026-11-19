// src: GUESS (confidence: low) [0x0092bd60]
struct UnkEntry28_0092bd60 {
    char pad[0x28];
};

extern char g_TableEnd_0092bd60;

// src: GUESS (confidence: low) [0x0092bd60]
UnkEntry28_0092bd60* GetEntryFromEnd_0092bd60(unsigned int idx) {
    if (idx < 0x42) {
        return (UnkEntry28_0092bd60*)(&g_TableEnd_0092bd60 - idx * sizeof(UnkEntry28_0092bd60));
    }
    return 0;
}
