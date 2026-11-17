// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x009459d0]
struct Obj_009459d0;

// src: GUESS (confidence: low)
struct Funcs_009459d0
{
    char pad[8];
    // src: GUESS (confidence: low)
    int (*fn)(int, int, Obj_009459d0*);
};

// src: GUESS (confidence: low)
struct Obj_009459d0
{
    char pad[68];
    // src: GUESS (confidence: low)
    const Funcs_009459d0* funcs;
};

// src: GUESS (confidence: low) [0x009459d0]
int Forward_009459d0(int a1, int a2, Obj_009459d0* obj)
{
    return obj->funcs->fn(a1, a2, obj);
}
