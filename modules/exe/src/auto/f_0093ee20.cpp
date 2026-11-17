// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x0093ee20]
struct Obj_0093ee20;

// src: GUESS (confidence: low)
struct Funcs_0093ee20
{
    char pad[24];
    // src: GUESS (confidence: low)
    int (*fn)(Obj_0093ee20*, int);
};

// src: GUESS (confidence: low)
struct Obj_0093ee20
{
    // src: GUESS (confidence: low)
    const Funcs_0093ee20* funcs;
};

// src: GUESS (confidence: low) [0x0093ee20]
int Forward_0093ee20(Obj_0093ee20* obj, int a2)
{
    return obj->funcs->fn(obj, a2);
}
