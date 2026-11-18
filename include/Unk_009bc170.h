#pragma once

// Placeholder: flags at 0x40 and two floats at 0x44/0x60. Rename once the
// owning type is known.

// src: GUESS (confidence: low) [0x009bc170]
struct Unk_009bc170
{
    char m_unk00[0x40];
    unsigned char m_flags;      // 0x40
    char m_unk41[3];
    float m_value;              // 0x44
    char m_unk48[0x18];
    float m_threshold;          // 0x60
};

// src: GUESS (confidence: low) [0x009bc170]
int ReachedThreshold_009bc170(const Unk_009bc170* item);
