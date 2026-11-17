// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x00968340]
struct Obj_00968340;

// src: GUESS (confidence: low)
struct Funcs_00968340
{
    char pad[4];
    // src: GUESS (confidence: low)
    int (*fn)(int, int, Obj_00968340*);
};

// src: GUESS (confidence: low)
struct Obj_00968340
{
    char pad[60];
    // src: GUESS (confidence: low)
    const Funcs_00968340* funcs;
};

// src: GUESS (confidence: low) [0x00968340]
int Forward_00968340(int a1, int a2, Obj_00968340* obj)
{
    return obj->funcs->fn(a1, a2, obj);
}
