// c5d-cflags: +/Od
// Pushes the object's value onto the global 8-entry stack; -1 when full.

// src: GUESS (confidence: low) [0x02de1e78]
extern int g_stackCount_02de1e78;
// src: GUESS (confidence: low) [0x02de1e50]
extern int g_stack_02de1e50[8];

// src: GUESS (confidence: low)
struct Object_008a4900
{
    char m_pad0[0x12c];
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x008a4900]
int PushValue_008a4900(Object_008a4900* object)
{
    if (g_stackCount_02de1e78 >= 8)
        return -1;
    g_stack_02de1e50[g_stackCount_02de1e78] = object->m_value;
    g_stackCount_02de1e78 = g_stackCount_02de1e78 + 1;
    return 0;
}
