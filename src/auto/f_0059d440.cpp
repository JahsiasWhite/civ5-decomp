// Destructor of a class with a vtable at 0x00a10754: it only resets the vtable
// pointer (the class has nothing else to clean up).
// c5d-vtable: 0x00a10754

class Vtbl_00a10754
{
public:
    virtual void Slot0();
    ~Vtbl_00a10754();
};

Vtbl_00a10754::~Vtbl_00a10754()
{
}
