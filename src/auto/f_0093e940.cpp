// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x0093e940]
struct Obj_0093e940;

// src: GUESS (confidence: low)
struct Funcs_0093e940
{
    char pad[12];
    // src: GUESS (confidence: low)
    int (*fn)(int, int, int, Obj_0093e940*, int);
};

// src: GUESS (confidence: low)
struct Obj_0093e940
{
    char pad[8];
    // src: GUESS (confidence: low)
    const Funcs_0093e940* funcs;
};

// src: GUESS (confidence: low) [0x0093e940]
int Forward_0093e940(int a1, int a2, int a3, Obj_0093e940* obj, int a5)
{
    return obj->funcs->fn(a1, a2, a3, obj, a5);
}
