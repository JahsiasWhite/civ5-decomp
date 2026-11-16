// c5d-cflags: +/Od
// Returns its argument unchanged. From an unoptimised (/Od) source file, so it
// keeps its frame.

// src: GUESS (confidence: low) [0x008a8620]
int ReturnArg_008a8620(int value)
{
    return value;
}
