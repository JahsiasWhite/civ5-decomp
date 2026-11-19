#include <stdio.h>

// src: GUESS (confidence: medium) [0x00a9cac8]
extern const char g_fmt_00a9cac8[];

// Prints a message to stderr.
// src: GUESS (confidence: low) [0x00903ef0]
void PrintError_00903ef0(const char* message)
{
    fprintf_s(stderr, g_fmt_00a9cac8, message);
}
