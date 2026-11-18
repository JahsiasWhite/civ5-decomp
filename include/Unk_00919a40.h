#pragma once

// Placeholder: the three floats at 0xa8 of the object 0x00919a40 reads.
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x00919a40]
struct UnkFloat3_00919a40
{
    float m_x;
    float m_y;
    float m_z;
};

// src: GUESS (confidence: low) [0x00919a40]
class Unk_00919a40
{
public:
    // src: GUESS (confidence: low) [0x00919a40]
    bool GetVector(UnkFloat3_00919a40* out);

    char m_unk000[0xa8];
    UnkFloat3_00919a40 m_vector;    // 0xa8
};
