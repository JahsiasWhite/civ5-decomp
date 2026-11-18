// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)

// src: LIB [0x00926be6]
extern "C" void* __cdecl malloc(unsigned int size);

// Allocation callback handed to a library; plain malloc.
// src: GUESS (confidence: medium) [0x00892110]
void* __stdcall AllocCallback_00892110(unsigned int size)
{
    void* p = malloc(size);
    return p;
}
