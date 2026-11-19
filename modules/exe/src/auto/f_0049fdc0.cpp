// Appends a line (text plus a newline) to an 8 KB text buffer; false if it doesn't fit.

#include <string.h>

// src: GUESS (confidence: low)
struct LineBuffer_004ab0f0
{
    // src: GUESS (confidence: low) [0x004ab0f0]
    bool AppendLine(const char* text);

    // src: GUESS (confidence: low)
    char m_text[0x2000];
};

bool LineBuffer_004ab0f0::AppendLine(const char* text)
{
    if (strcat_s(m_text, sizeof(m_text), text) != 0)
    {
        return false;
    }
    strcat_s(m_text, sizeof(m_text), "\n");
    return true;
}
