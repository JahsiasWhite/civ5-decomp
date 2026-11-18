// c5d-cflags: +/Od
// Returns the object's embedded data (at its stored offset), or null when
// flag 0x100 says it isn't embedded.

// src: GUESS (confidence: low)
struct Object_00897f90
{
    char m_pad0[0x100];
    // src: GUESS (confidence: low)
    int m_dataOffset;
    int m_104;
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

// src: GUESS (confidence: low) [0x00897f90]
char* GetEmbeddedData_00897f90(Object_00897f90* object)
{
    char* data;
    if (object->m_flags & 0x100)
        data = 0;
    else
        data = (char*)object + object->m_dataOffset;
    return data;
}
