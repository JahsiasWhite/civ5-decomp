// c5d-cflags: +/Od
// Turns the two offsets in the object's table into addresses relative to
// the object.

// src: GUESS (confidence: low)
struct Table_0089f700
{
    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    int m_first;
    // src: GUESS (confidence: low)
    int m_second;
};

// src: GUESS (confidence: low)
struct Object_0089f700
{
    char m_pad0[0x17c];
    // src: GUESS (confidence: low)
    Table_0089f700* m_table;
};

// src: GUESS (confidence: low) [0x0089f700]
void Relocate_0089f700(Object_0089f700* object)
{
    Table_0089f700* table = object->m_table;
    table->m_first += (int)object;
    table->m_second += (int)object;
}
