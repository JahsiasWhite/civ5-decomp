// src: EXE [0x008f9730]
void Fn_008f9730();
// src: EXE [0x008f8dd0]
void Fn_008f8dd0();
// src: EXE [0x008f9140]
void Fn_008f9140();
// src: EXE [0x008f9bc0]
void Fn_008f9bc0();

// src: GUESS (confidence: high) [0x008fa030]
void* GetFn_008fa030(int x)
{
    if (x == 1) return (void*)&Fn_008f9730;
    if (x == 0) return (void*)&Fn_008f8dd0;
    if (x == 2) return (void*)&Fn_008f9140;
    if (x == 3) return (void*)&Fn_008f9bc0;
    return 0;
}
