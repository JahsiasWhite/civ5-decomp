// src: GUESS (confidence: low) [0x0085b0e0]
extern void DefaultFunc_0085b020();

class Class_0085b0e0
{
public:
    int m_0;
    int m_4;
    void (*m_fn)();

    void SetCallback(void (*fn)());
};

void Class_0085b0e0::SetCallback(void (*fn)())
{
    m_fn = fn ? fn : DefaultFunc_0085b020;
}
