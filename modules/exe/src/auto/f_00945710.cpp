// Forwards its arguments to a function in the object's table of callbacks
// (a C-style interface: a struct of function pointers).

// src: GUESS (confidence: low) [0x00945710]
struct Obj_00945710;

// src: GUESS (confidence: low)
struct Funcs_00945710
{
    char pad[20];
    // src: GUESS (confidence: low)
    int (*fn)(Obj_00945710*, int);
};

// src: GUESS (confidence: low)
struct Obj_00945710
{
    // src: GUESS (confidence: low)
    const Funcs_00945710* funcs;
};

// src: GUESS (confidence: low) [0x00945710]
int Forward_00945710(Obj_00945710* obj, int a2)
{
    return obj->funcs->fn(obj, a2);
}
