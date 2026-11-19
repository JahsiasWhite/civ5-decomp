// src: GUESS (confidence: low) [0x00928000]
struct Sub_00928000 {
    char pad[4];
    void* f4;
};

// src: GUESS (confidence: low) [0x00928000]
struct Obj_00928000 {
    char pad[0x74];
    void* f74;
    char pad2[0xd8 - 0x78];
    Sub_00928000* fd8;
};

// src: GUESS (confidence: low) [0x00928000]
void* GetPtr_00928000(Obj_00928000* ecx) {
    if (ecx) {
        if (ecx->f74) return ecx->f74;
        if (ecx->fd8 && ecx->fd8->f4) return ecx->fd8->f4;
    }
    return 0;
}
