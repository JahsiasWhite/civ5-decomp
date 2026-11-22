// src: GUESS (confidence: low)
struct TilePoint_0050d2b0 {
    unsigned int x;
    unsigned int y;
};

// src: GUESS (confidence: low)
struct TileBlock_0050d2b0 {
    short flag;
    short pad;
    union {
        short flatVal;
        int tileIdx;
    };
};

// src: GUESS (confidence: low)
struct TileMap_0050d2b0 {
    int m_00;
    int m_04;
    unsigned int m_width;
    int m_0c;
    TileBlock_0050d2b0* m_blocks;
    int m_14;
    int m_18;
    unsigned short* m_tiles;

    unsigned short GetTile(const TilePoint_0050d2b0* pt);
};

// src: GUESS (confidence: medium) [0x0050d2b0]
unsigned short TileMap_0050d2b0::GetTile(const TilePoint_0050d2b0* pt) {
    unsigned int y = pt->y;
    unsigned int x = pt->x;
    TileBlock_0050d2b0* blk = &m_blocks[(y >> 4) * m_width + (x >> 4)];
    if (blk->flag != 0) {
        return blk->flatVal;
    }
    return m_tiles[(((blk->tileIdx << 4) + (y & 0xf)) << 4) + (x & 0xf)];
}
