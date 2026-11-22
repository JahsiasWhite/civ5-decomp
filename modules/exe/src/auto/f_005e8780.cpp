// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct GridPt_005e8780 {
    unsigned int x;
    unsigned int y;
};

// src: GUESS (confidence: low)
struct Cell20_005e8780 {
    int a, b, c, d, e;
};

// src: GUESS (confidence: low)
struct Grid_005e8780 {
    int m_00;
    Cell20_005e8780* m_data;
    int m_08;
    int m_0c;
    unsigned int m_width;
    unsigned int m_height;

    bool SetCell(const GridPt_005e8780* pt, const Cell20_005e8780* val);
};

// src: GUESS (confidence: medium) [0x005e8780]
bool Grid_005e8780::SetCell(const GridPt_005e8780* pt, const Cell20_005e8780* val) {
    if (pt->x >= m_width || pt->y >= m_height) {
        return false;
    }
    m_data[pt->y * m_width + pt->x] = *val;
    return true;
}
