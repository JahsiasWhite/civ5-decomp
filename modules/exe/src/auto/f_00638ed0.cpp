// Replaces the object's font with one built from the description.

#include <windows.h>

// src: GUESS (confidence: low) [0x00a8cd88]
class FontHolder_00638ed0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    // src: GUESS (confidence: low) [0x00638ed0]
    virtual void SetFont(const LOGFONTA* description);

    char m_pad4[0x58 - 4];
    // src: GUESS (confidence: low)
    HFONT m_font;
    char m_pad5c[0x64 - 0x5c];
    // src: GUESS (confidence: low)
    int m_dirty;
};

void FontHolder_00638ed0::SetFont(const LOGFONTA* description)
{
    if (m_font)
    {
        DeleteObject(m_font);
        m_font = 0;
    }
    m_font = CreateFontIndirectA(description);
    m_dirty = 1;
}
