// c5d-cflags: +/Od
// Returns the current frame's entry data (past its 4-byte header), or null
// when the frame index is out of range.

// src: GUESS (confidence: low)
extern int g_iGlobalCounter_02de1ea0;

// src: GUESS (confidence: low)
struct Frames_008a8480
{
    char m_pad0[0x28];
    // src: GUESS (confidence: low)
    int m_count;
    // src: GUESS (confidence: low)
    char** m_entries;
};

// src: GUESS (confidence: low) [0x008a8480]
char* GetCurrentData_008a8480(Frames_008a8480* frames)
{
    char* entry;
    if (g_iGlobalCounter_02de1ea0 >= frames->m_count)
        return 0;
    entry = frames->m_entries[g_iGlobalCounter_02de1ea0];
    return entry + 4;
}
