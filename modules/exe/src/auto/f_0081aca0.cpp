// Restores the saved MouseKeys and StickyKeys accessibility settings (each
// only if it was saved).

#include <windows.h>

// src: GUESS (confidence: medium)
class AccessibilitySettings_0081aca0
{
public:
    // src: GUESS (confidence: medium) [0x0081aca0]
    void Restore();

    // src: GUESS (confidence: medium)
    MOUSEKEYS m_mouseKeys;
    // src: GUESS (confidence: medium)
    STICKYKEYS m_stickyKeys;
};

void AccessibilitySettings_0081aca0::Restore()
{
    if (m_mouseKeys.cbSize)
        SystemParametersInfoA(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), &m_mouseKeys, SPIF_SENDCHANGE);
    if (m_stickyKeys.cbSize)
        SystemParametersInfoA(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &m_stickyKeys, SPIF_SENDCHANGE);
}
