// c5d-model: Gemini 3.8 Flash
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

    // src: GUESS (confidence: medium) [0x008f4210]
    void Init();
};

void Unk_00b86914::Init()
{
    m_vftable = g_vtable_00b86914;
}
