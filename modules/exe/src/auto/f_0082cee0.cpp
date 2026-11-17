// c5d-model: Gemini 4 Hydrogen
// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Installs the vtable for Unk_00b8971c.

// src: GUESS (confidence: medium) [0x00b8971c]
extern void* const g_vtable_00b8971c[];

// src: GUESS (confidence: medium)
class Unk_00b8971c
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;

    // src: GUESS (confidence: medium) [0x0082cee0]
    void Destroy();
};

void Unk_00b8971c::Destroy()
{
    m_vftable = g_vtable_00b8971c;
}
