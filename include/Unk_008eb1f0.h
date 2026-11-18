#pragma once

// Placeholder: an object with a pointer array at 0x64 (begin/end pointers).
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008eb1f0]
struct UnkArrayOwner
{
    unsigned int GetItemCount() const { return m_itemsEnd - m_itemsBegin; }

    char m_unk00[0x64];
    void** m_itemsBegin;    // 0x64
    void** m_itemsEnd;      // 0x68
};

// src: GUESS (confidence: low) [0x008eb1f0]
struct UnkArrayOwnerRef
{
    // src: GUESS (confidence: low) [0x008eb1f0]
    void** GetItems();

    UnkArrayOwner* m_owner;
};
