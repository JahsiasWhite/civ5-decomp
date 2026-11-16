// c5d-model: Gemini 4 Hydrogen
// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Installs the vtable for Unk_00b859ac.

// src: GUESS (confidence: medium) [0x00b859ac]
extern void* const g_vtable_00b859ac[];

// src: GUESS (confidence: medium)
class Unk_00b859ac
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;

    // src: GUESS (confidence: medium) [0x00714570]
    void Destroy();
};

void Unk_00b859ac::Destroy()
{
    m_vftable = g_vtable_00b859ac;
}
