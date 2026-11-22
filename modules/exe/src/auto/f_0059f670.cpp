// src: GUESS (confidence: low) [0x0059f670]
extern void DefaultFunc_0085b020();

class Class_0059f670
{
public:
    void (*m_fn)();

    void SetCallback(void (*fn)());
};

void Class_0059f670::SetCallback(void (*fn)())
{
    m_fn = fn ? fn : DefaultFunc_0085b020;
}
