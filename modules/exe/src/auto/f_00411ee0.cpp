// c5d-review: arguments and fields are volatile only to keep the loads and stores
// in source order; probably the area's real compiler flags differ (try c5d-cflags).
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
