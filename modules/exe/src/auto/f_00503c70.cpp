// src: GUESS (confidence: low)
struct UnkCmd_00503c70
{
    unsigned int m_size;
    int m_pad04;
    int m_arg;
    int m_pad0c;
    void* m_obj;
    void (__thiscall* m_fn)(void*, int, void*);
    int m_pad18;
    int m_pad1c;
    char m_data[1];
};

// src: GUESS (confidence: low)
struct UnkBucket_00503c70
{
    unsigned int m_size;
    int m_pad04;
    char* m_buf;
};

// src: GUESS (confidence: low)
struct UnkQueue_00503c70
{
    UnkBucket_00503c70 m_buckets[1];

    void Flush_00503c70(int idx);
};

// src: GUESS (confidence: medium) [0x00503c70]
void UnkQueue_00503c70::Flush_00503c70(int idx)
{
    UnkBucket_00503c70* b = &m_buckets[idx];
    unsigned int sz = b->m_size;
    if (sz > 0)
    {
        char* p = b->m_buf;
        char* end = p + sz;
        while (p != end)
        {
            UnkCmd_00503c70* cmd = (UnkCmd_00503c70*)p;
            cmd->m_fn(cmd->m_obj, cmd->m_arg, cmd->m_data);
            p += cmd->m_size;
        }
        b->m_size = 0;
    }
}
