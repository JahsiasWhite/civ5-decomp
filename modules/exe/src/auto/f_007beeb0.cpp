// Returns the address of a global data item at 0x00b29ec8. What it holds isn't
// known yet.

// src: GUESS (confidence: low) [0x00b29ec8]
extern char g_data_00b29ec8;

// src: GUESS (confidence: low) [0x007beeb0]
char* GetData_007beeb0()
{
    return &g_data_00b29ec8;
}
