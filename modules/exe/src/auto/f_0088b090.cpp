// Calls the no-argument callback in slot 0x60 of the object's function table.

// src: GUESS (confidence: low)
struct Funcs_00927cc0
{
    char pad[0x60];
    // src: GUESS (confidence: low)
    void (*fn)();
};

// src: GUESS (confidence: low)
struct Obj_00927cc0
{
    char pad[8];
    // src: GUESS (confidence: low)
    const Funcs_00927cc0* funcs;
};

// src: GUESS (confidence: low) [0x00927cc0]
void CallSlot60_00927cc0(Obj_00927cc0* obj)
{
    obj->funcs->fn();
}
