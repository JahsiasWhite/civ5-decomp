// c5d-model: Gemini 3.8 Flash
extern const void* const kVtable_00b89b24[];
extern const void* const kVtable_00b89890[];
extern const void* const kVtable_00b86914[];

class Host_0083ee60 {
public:
    const void* const* vtable0;
    int pad1;
    const void* const* vtable2;
    const void* const* vtable3;
    // src: GUESS (confidence: high) [0x0083ee60]
    void __thiscall ResetVtables();
};

void Host_0083ee60::ResetVtables() {
    vtable3 = kVtable_00b89b24;
    vtable2 = kVtable_00b89890;
    vtable0 = kVtable_00b86914;
}
