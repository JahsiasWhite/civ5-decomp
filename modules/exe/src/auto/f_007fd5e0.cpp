// c5d-cflags: -/O2 +/Od
// src: GUESS (confidence: low)
struct UnkItem288_007fd5e0
{
    int data[72];
};

// src: GUESS (confidence: low)
struct UnkArr_007fd5e0
{
    char pad_0[0x124];
    int m_count;
    int pad_128;
    UnkItem288_007fd5e0* m_data;
};

// src: GUESS (confidence: low)
int __cdecl SetItem_007fd5e0(UnkArr_007fd5e0* self, int idx, const UnkItem288_007fd5e0* item)
{
    if (idx < 0 || idx >= self->m_count)
        return -1;
    self->m_data[idx] = *item;
    return 0;
}
