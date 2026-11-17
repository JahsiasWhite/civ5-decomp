// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x00968360]
struct Obj_00968360;

// src: GUESS (confidence: low)
struct Funcs_00968360
{
    char pad[12];
    // src: GUESS (confidence: low)
    void (*fn)(int, int, int, Obj_00968360*);
};

// src: GUESS (confidence: low)
struct Obj_00968360
{
    char pad[60];
    // src: GUESS (confidence: low)
    const Funcs_00968360* funcs;
};

// src: GUESS (confidence: low) [0x00968360]
void Forward_00968360(int a1, int a2, int a3, Obj_00968360* obj)
{
    obj->funcs->fn(a1, a2, a3, obj);
}
