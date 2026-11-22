// src: GUESS (confidence: low) [0x0085b0c0]
extern void DefaultFunc_006652a0();

class Class_0085b0c0
{
public:
    int m_0;
    void (*m_fn)();

    void SetCallback(void (*fn)());
};

void Class_0085b0c0::SetCallback(void (*fn)())
{
    m_fn = fn ? fn : DefaultFunc_006652a0;
}
