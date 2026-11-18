// c5d-cflags: +/Od
// Clears a stream's state and frees its buffer through the allocator hook.

// src: GUESS (confidence: low)
struct Stream_008a5230
{
    char m_pad0[0xc];
    // src: GUESS (confidence: low)
    int m_state;
    char m_pad10[8];
    // src: GUESS (confidence: low)
    void* m_buffer;
};

// src: GUESS (confidence: low)
struct Owner_008a5230
{
    char m_pad0[0x1c];
    // src: GUESS (confidence: low)
    Stream_008a5230* m_stream;
};

// src: GUESS (confidence: low) [0x02de1e8c]
extern void (*g_freeHook_02de1e8c)(void* p);

// src: GUESS (confidence: low) [0x008a5230]
void CloseStream_008a5230(Owner_008a5230* owner)
{
    Stream_008a5230* stream = owner->m_stream;
    stream->m_state = 0;
    g_freeHook_02de1e8c(stream->m_buffer);
}
