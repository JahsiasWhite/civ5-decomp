// c5d-cflags: -/EHsc   (no unwind frame around the copies)
// Fills raw storage with `count` copies of an (id, name) record.

#include <string>
#include <new>

// src: GUESS (confidence: low)
struct NamedId_00544940
{
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    std::string m_name;
};

// src: GUESS (confidence: low) [0x00544940]
void UninitializedFill_00544940(NamedId_00544940* dest, unsigned int count, const NamedId_00544940& value)
{
    for (; 0 < count; --count, ++dest)
        new (dest) NamedId_00544940(value);
}
