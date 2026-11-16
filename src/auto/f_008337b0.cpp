// Returns the address just past the 4-byte header of the object's buffer.

#include "UnkHeaderedBuffer.h"

char* UnkHeaderedBuffer::GetDataAfterHeader()
{
    return m_pBuffer + 4;
}
