// c5d-cflags: +/Od
// Returns its argument unchanged. From an unoptimised (/Od) source file, so it
// keeps its frame.

// src: GUESS (confidence: low) [0x00897c70]
int ReturnArg_00897c70(int value)
{
    return value;
}
