// Constructs a log entry: a 32-character tag and a formatted 96-character
// message.

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

// src: GUESS (confidence: low)
struct LogEntry_00553760
{
    // src: GUESS (confidence: low) [0x00553760]
    LogEntry_00553760(const char* tag, const char* format, ...);

    // src: GUESS (confidence: low)
    char m_tag[0x20];
    // src: GUESS (confidence: low)
    char m_message[0x60];
};

LogEntry_00553760::LogEntry_00553760(const char* tag, const char* format, ...)
{
    strcpy_s(m_tag, sizeof(m_tag), tag);
    va_list args;
    va_start(args, format);
    vsprintf_s(m_message, sizeof(m_message), format, args);
}
