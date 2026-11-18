#pragma once

// Table of stdcall entry points that the thunks around 0x00926390 forward to once
// the service flag is set. Only the slots those thunks use are named.

typedef unsigned long (__stdcall* UnkServiceFn1)(unsigned long);
typedef unsigned long (__stdcall* UnkServiceFn2)(unsigned long, unsigned long);
typedef unsigned long (__stdcall* UnkServiceFn3)(unsigned long, unsigned long, unsigned long);

// src: GUESS (confidence: low) [0x06198000]
struct UnkServiceTable {
    void* m_unk00[5];
    UnkServiceFn1 m_fn14;   // 0x14
    UnkServiceFn1 m_fn18;   // 0x18
    void* m_unk1c[4];
    UnkServiceFn1 m_fn2c;   // 0x2c
    void* m_unk30;
    UnkServiceFn3 m_fn34;   // 0x34
    void* m_unk38[10];
    UnkServiceFn2 m_fn60;   // 0x60
    void* m_unk64;
    UnkServiceFn1 m_fn68;   // 0x68
};

// src: GUESS (confidence: medium) [0x0606c9d4]
extern int g_serviceActive_0606c9d4;
// src: GUESS (confidence: low) [0x06198000]
extern UnkServiceTable* g_serviceTable_06198000;

// Returned by the thunks while the service is not running (ERROR_SERVICE_NOT_ACTIVE).
#define UNK_SERVICE_NOT_ACTIVE 0x426
