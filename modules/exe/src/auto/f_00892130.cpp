// c5d-cflags: +/Od
// Frees the block a pointer refers to and clears the pointer.

extern "C" void __cdecl free(void* p);

// src: GUESS (confidence: low) [0x00892130]
void __stdcall FreeAndClear_00892130(void** block)
{
    if (block && *block)
    {
        free(*block);
        *block = 0;
    }
}
