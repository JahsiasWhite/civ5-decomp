#pragma once

// Placeholder: a one-pointer handle returned by value (through a hidden return
// pointer, so the original type isn't plain data), made by the factory function
// stored at 0x02dd201c. Rename once the type is known.

// src: GUESS (confidence: low) [0x0066a390]
struct UnkHandle_0066a390
{
    UnkHandle_0066a390(void* object) : m_object(object) {}
    UnkHandle_0066a390(const UnkHandle_0066a390& other);

    void* m_object;
};

typedef void* (__cdecl* UnkHandleFactory_0066a390)();

// src: GUESS (confidence: low) [0x02dd201c]
extern UnkHandleFactory_0066a390 g_handleFactory_02dd201c;

// src: GUESS (confidence: low) [0x0066a390]
UnkHandle_0066a390 MakeHandle_0066a390();
