// Granny memory arena: frees every block in the arena's chain.

extern "C" void (__cdecl *g_iGlobalB_00cb38b4)(const char* file, int line, void* block);

// src: GUESS (confidence: low)
struct ArenaBlock_009bbe10
{
    int m_size;
    // src: GUESS (confidence: low)
    ArenaBlock_009bbe10* m_next;
};

// src: GUESS (confidence: low) [0x009bbe10]
void FreeArenaBlocks_009bbe10(ArenaBlock_009bbe10* block)
{
    while (block)
    {
        ArenaBlock_009bbe10* current = block;
        block = block->m_next;
        g_iGlobalB_00cb38b4("..\\granny_memory_arena.cpp", 77, current);
    }
}
