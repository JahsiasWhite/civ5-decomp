// Prepares the DC for drawing text once: selects the font (keeping the old
// one) and sets white text on a black background.

#include <windows.h>

// src: GUESS (confidence: low) [0x00a840c0]
class TextSurface_004e5a00
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low) [0x004e5a00]
    virtual void BeginText();

    char m_pad4[0x14 - 4];
    // src: GUESS (confidence: low)
    HDC m_dc;
    // src: GUESS (confidence: low)
    HFONT m_font;
    // src: GUESS (confidence: low)
    HGDIOBJ m_oldFont;
};

void TextSurface_004e5a00::BeginText()
{
    if (!m_oldFont)
    {
        m_oldFont = SelectObject(m_dc, m_font);
        SetTextColor(m_dc, 0xffffff);
        SetBkColor(m_dc, 0);
    }
}
