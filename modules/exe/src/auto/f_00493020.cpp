#include "Unk_005a6040.h"

// src: EXE [0x009dea08]
extern "C" char aDefault_009dea08[];

UnkNamed_005a6040::UnkNamed_005a6040(const char* name)
    : m_name(name ? name : aDefault_009dea08)
{
}
