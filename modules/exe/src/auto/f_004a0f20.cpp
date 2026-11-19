// c5d-model: Gemini 4 Hydrogen
// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Installs the vtable for Unk_00b84494.

// src: GUESS (confidence: medium) [0x00b84494]
extern void* const g_vtable_00b84494[];

// src: GUESS (confidence: medium)
class Unk_00b84494
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;

    // src: GUESS (confidence: medium) [0x006e8bd0]
    void Destroy();
};

void Unk_00b84494::Destroy()
{
    m_vftable = g_vtable_00b84494;
}
