// c5d-model: Gemini 3.8 Flash
// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Installs the vtable for Unk_00a9b758.

// src: GUESS (confidence: medium) [0x00a9b758]
extern void* const g_vtable_00a9b758[];

// src: GUESS (confidence: medium)
class Unk_00a9b758
{
public:
    // src: GUESS (confidence: high)
    const void* m_vftable;

    // src: GUESS (confidence: medium) [0x008fad90]
    void Destroy();
};

void Unk_00a9b758::Destroy()
{
    m_vftable = g_vtable_00a9b758;
}
