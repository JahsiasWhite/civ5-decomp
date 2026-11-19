// c5d-model: Gemini 4 Hydrogen
// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Installs the vtable for Unk_00b86914.

// src: GUESS (confidence: medium) [0x00b86914]
extern void* const g_vtable_00b86914[];

// src: GUESS (confidence: medium)
class Unk_00b86914
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;

    // src: GUESS (confidence: medium) [0x00831710]
    void Destroy();
};

void Unk_00b86914::Destroy()
{
    m_vftable = g_vtable_00b86914;
}
