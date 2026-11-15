// c5d-model: claude-opus-5-5
// c5d-cflags: +/Oy-

// Strict-weak-ordering predicate on two unsigned 64-bit values passed by pointer.
int __stdcall UInt64PtrLess(const unsigned __int64* a, const unsigned __int64* b)
{
    return *a < *b;
}
