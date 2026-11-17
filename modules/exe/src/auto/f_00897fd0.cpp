// c5d-cflags: +/Od
// Returns its argument unchanged. From an unoptimised (/Od) source file, so it
// keeps its frame.

// src: GUESS (confidence: low) [0x00897fd0]
int ReturnArg_00897fd0(int value)
{
    return value;
}
