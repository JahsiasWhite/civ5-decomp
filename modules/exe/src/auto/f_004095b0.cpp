// c5d-cflags: +/Oy-

struct BlockLayout_7c3030
{
    char pad[0x100];
    int m_count;
    int m_stride;
};

class BlockAllocator_7c3030
{
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Alloc(void* dest, int bytes);

    void AllocBlock(void* dest);

    BlockLayout_7c3030* m_layout;
};

void BlockAllocator_7c3030::AllocBlock(void* dest)
{
    Alloc(dest, m_layout->m_stride * m_layout->m_count + 8);
}
