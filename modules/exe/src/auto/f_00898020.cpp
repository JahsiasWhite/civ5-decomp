// c5d-cflags: +/Od
// Returns its argument unchanged. From an unoptimised (/Od) source file, so it
// keeps its frame.

// src: GUESS (confidence: low) [0x00898020]
int ReturnArg_00898020(int value)
{
    return value;
}
