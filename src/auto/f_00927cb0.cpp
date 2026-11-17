// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x00927cb0]
struct Obj_00927cb0;

// src: GUESS (confidence: low)
struct Funcs_00927cb0
{
    char pad[80];
    // src: GUESS (confidence: low)
    int (*fn)(Obj_00927cb0*);
};

// src: GUESS (confidence: low)
struct Obj_00927cb0
{
    char pad[8];
    // src: GUESS (confidence: low)
    const Funcs_00927cb0* funcs;
};

// src: GUESS (confidence: low) [0x00927cb0]
int Forward_00927cb0(Obj_00927cb0* obj)
{
    return obj->funcs->fn(obj);
}
