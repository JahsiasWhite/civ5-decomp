// src: GUESS (confidence: low) [0x00928030]
struct Sub_00928030 {
    char pad[8];
    void* f8;
};

// src: GUESS (confidence: low) [0x00928030]
struct Obj_00928030 {
    char pad[0x78];
    void* f78;
    char pad2[0xd8 - 0x7c];
    Sub_00928030* fd8;
};

// src: GUESS (confidence: low) [0x00928030]
void* GetPtr_00928030(Obj_00928030* ecx) {
    if (ecx) {
        if (ecx->f78) return ecx->f78;
        if (ecx->fd8 && ecx->fd8->f8) return ecx->fd8->f8;
    }
    return 0;
}
