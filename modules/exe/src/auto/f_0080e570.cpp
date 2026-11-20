// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low) [0x0080e570]
struct Unk_0080e570
{
    char m_pad00[0x318];  // +0x00
    int* m_pFlags318;     // +0x318
};

// src: GUESS (confidence: high) [0x0080e570]
int HasFlag4_0080e570(Unk_0080e570* p)
{
    int* flags = p->m_pFlags318;
    return ((*flags) & 4) != 0;
}
