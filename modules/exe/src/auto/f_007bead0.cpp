#include <stdio.h>

typedef unsigned char uint8_t;
typedef int int32_t;
typedef short int16_t;

// src: GUESS (confidence: low) [0x007bead0]
struct Archive7BEAD0 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual unsigned int getSize();
};

// src: GUESS (confidence: low) [0x007bead0]
struct NetPlotSyncCheck {
    uint8_t       m_pad00[0x30];
    int32_t       m_iPlayer;
    int16_t       m_sX;
    int16_t       m_sY;
    Archive7BEAD0 m_archive;

    // src: GUESS (confidence: low) [0x007bead0]
    void DebugString(char* szBuf, size_t uiSize);
};

void NetPlotSyncCheck::DebugString(char* szBuf, size_t uiSize) {
    sprintf_s(
        szBuf,
        uiSize,
        "NetPlotSyncCheck(Player=%d, Plot(%d, %d), ArchiveDataSize=%u",
        m_iPlayer,
        m_sX,
        m_sY,
        m_archive.getSize()
    );
}
