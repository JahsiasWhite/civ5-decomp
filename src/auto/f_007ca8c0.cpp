// c5d-model: claude-opus-5-5
// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)

// Object that holds three 32-bit components at offset 0x40.
struct Triple40Holder
{
    char pad[0x40];
    volatile int x;
    volatile int y;
    volatile int z;
};

// Stores the three components into the object, if the object is non-null.
// The fields and arguments are volatile: the original keeps every load and
// store in source order.
void SetTriple40(Triple40Holder* obj, volatile int x, volatile int y, volatile int z)
{
    if (obj)
    {
        obj->x = x;
        obj->y = y;
        obj->z = z;
    }
}
