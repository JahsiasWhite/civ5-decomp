// src: LIB
struct GrannyArena_0091f220
{
    int m_f00;  // +0x00
    int m_f04;  // +0x04
};

// src: LIB [0x00b447c4]
extern GrannyArena_0091f220* (__cdecl* g_grannyAlloc_0091f220)(const char* file, int line, int align, int size);

// src: LIB [0x0091f220]
GrannyArena_0091f220* NewArena_0091f220()
{
    GrannyArena_0091f220* arena = (*g_grannyAlloc_0091f220)("..\\granny_memory_arena.cpp\0", 0x23, 4, 8);
    if (arena)
    {
        arena->m_f00 = 4;
        arena->m_f04 = 0;
    }
    return arena;
}
