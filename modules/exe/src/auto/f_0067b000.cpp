// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class; replace once the class and its virtual methods are known.
// Constructs a small polymorphic object: installs its vtable and clears the
// three data fields that follow it; returns the object like a constructor.

extern void* const g_vtable_00a41714[];

struct VtblTripleObject
{
    const void* vtbl;
    int field4;
    int field8;
    int fieldC;

    VtblTripleObject* Construct();
};

VtblTripleObject* VtblTripleObject::Construct()
{
    vtbl = g_vtable_00a41714;
    field8 = 0;
    fieldC = 0;
    field4 = 0;
    return this;
}
