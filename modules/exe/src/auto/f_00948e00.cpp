// Expects two zero bytes at the cursor when there are at least two bytes
// left; consumes them. Nothing left is fine; one byte left is an error.

// src: GUESS (confidence: low) [0x00948e00]
int ReadTwoZeroBytes_00948e00(const char** cursor, int remaining)
{
    if (remaining <= 0)
        return 1;
    if (remaining < 2)
        return 0;
    const char* p = *cursor;
    if (p[0] != 0 || p[1] != 0)
        return 0;
    *cursor = p + 2;
    return 1;
}
