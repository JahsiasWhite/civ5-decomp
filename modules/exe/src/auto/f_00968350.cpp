// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x00968350]
struct Obj_00968350;

// src: GUESS (confidence: low)
struct Funcs_00968350
{
    char pad[8];
    // src: GUESS (confidence: low)
    int (*fn)(Obj_00968350*, int);
};

// src: GUESS (confidence: low)
struct Obj_00968350
{
    char pad[60];
    // src: GUESS (confidence: low)
    const Funcs_00968350* funcs;
};

// src: GUESS (confidence: low) [0x00968350]
int Forward_00968350(Obj_00968350* obj, int a2)
{
    return obj->funcs->fn(obj, a2);
}
