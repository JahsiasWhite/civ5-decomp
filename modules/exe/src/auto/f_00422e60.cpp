#include <cstring>

// src: GUESS (confidence: low)
struct UnkStrPtr_00422e60
{
    const char* m_str;

    bool __thiscall Equals_00422e60(const UnkStrPtr_00422e60* other) const;
};

bool UnkStrPtr_00422e60::Equals_00422e60(const UnkStrPtr_00422e60* other) const
{
    return std::strcmp(m_str, other->m_str) == 0;
}
