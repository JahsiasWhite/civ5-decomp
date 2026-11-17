// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x009459c0]
struct Obj_009459c0;

// src: GUESS (confidence: low)
struct Funcs_009459c0
{
    char pad[4];
    // src: GUESS (confidence: low)
    int (*fn)(Obj_009459c0*);
};

// src: GUESS (confidence: low)
struct Obj_009459c0
{
    char pad[68];
    // src: GUESS (confidence: low)
    const Funcs_009459c0* funcs;
};

// src: GUESS (confidence: low) [0x009459c0]
int Forward_009459c0(Obj_009459c0* obj)
{
    return obj->funcs->fn(obj);
}
