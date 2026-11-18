// Appends formatted text (and its terminator) to a 512 KB text buffer.

#include <stdio.h>
#include <stdarg.h>

// src: GUESS (confidence: low)
struct TextBuffer_0066ab70
{
    // src: GUESS (confidence: low)
    int m_length;
    int m_04;
    // src: GUESS (confidence: low)
    char m_text[0x80000];
};

// src: GUESS (confidence: low) [0x0066ab70]
void AppendFormat_0066ab70(TextBuffer_0066ab70* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    buffer->m_length += vsprintf_s(buffer->m_text + buffer->m_length, 0x80000 - buffer->m_length, format, args) + 1;
}
