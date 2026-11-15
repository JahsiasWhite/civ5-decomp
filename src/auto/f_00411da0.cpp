// c5d-model: claude-opus-5-5
// Constructs a block-pool style allocator descriptor: clears its header
// fields, sets fixed size limits and clears the 32 two-list buckets.

struct PoolList
{
    void* head;
    void* tail;
    int pad[6];

    PoolList() : head(0), tail(0) {}
};

struct PoolBucket
{
    PoolList used;
    PoolList freed;
};

struct PoolSlot
{
    void* ptr;
    int extra;

    PoolSlot() : ptr(0) {}
};

struct PoolDescriptor
{
    PoolSlot first;
    PoolSlot second;
    int count;
    int maxBytes;
    int blockBytes;
    int chunkBytes;
    PoolBucket buckets[32];

    PoolDescriptor();
};

PoolDescriptor::PoolDescriptor()
    : count(0),
      maxBytes(0x800000), blockBytes(0x10000), chunkBytes(0x800)
{
}
