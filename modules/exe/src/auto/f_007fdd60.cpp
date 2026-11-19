// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)

// src: EXE [0x02de1e20]
extern int g_iGlobal_02de1e20;

// Steps the global cursor past the record it points at (0x2c-byte header plus
// the length stored at 0x24).
// src: GUESS (confidence: low) [0x00897cd0]
void AdvanceGlobalCursor_00897cd0()
{
    g_iGlobal_02de1e20 = g_iGlobal_02de1e20 + *(int*)(g_iGlobal_02de1e20 + 0x24) + 0x2c;
}
