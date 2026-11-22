// Calls the object's virtual function in slot 13 (vtable offset 0x34) and
// returns its result. Linked code shares this body across several classes, so
// the class below is a stand-in with that one slot.

struct Obj_00444280
{
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11();
    virtual void V12();
    virtual int V13();

    int Forward();
};

// src: GUESS (confidence: low) [0x00444280]
int Obj_00444280::Forward()
{
    return V13();
}
