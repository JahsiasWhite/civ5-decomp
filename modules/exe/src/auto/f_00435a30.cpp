// src: GUESS (confidence: low) [0x060274c8]
extern char g_empty_00435a30;

// src: GUESS (confidence: low) [0x00435a30]
struct Unk_00435a30
{
    unsigned char m_f00;  // +0x00
    int m_f04;            // +0x04
    int m_f08;            // +0x08
    int m_f0c;            // +0x0c
    int m_f10;            // +0x10
    int m_pad14;          // +0x14
    char* m_f18;          // +0x18
    char* m_f1c;          // +0x1c
    char* m_f20;          // +0x20
    char* m_f24;          // +0x24

    // src: GUESS (confidence: high) [0x00435a30]
    Unk_00435a30();
};

// src: GUESS (confidence: high) [0x00435a30]
Unk_00435a30::Unk_00435a30()
    : m_f00(0)
    , m_f04(0)
    , m_f08(0)
    , m_f0c(0)
    , m_f10(0)
    , m_f18(&g_empty_00435a30)
    , m_f1c(&g_empty_00435a30)
    , m_f20(&g_empty_00435a30)
    , m_f24(&g_empty_00435a30)
{
}
