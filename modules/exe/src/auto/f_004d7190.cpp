#include <string.h>
#include "Unk_00468210.h"

void Unk_00468210::Fill(unsigned char value)
{
    memset(m_buffer, value, m_size);
}
