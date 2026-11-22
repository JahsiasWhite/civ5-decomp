// Returns the address of a global data item at 0x02c71314. What it holds isn't
// known yet.

// src: GUESS (confidence: low) [0x02c71314]
extern char g_data_02c71314;

// src: GUESS (confidence: low) [0x007d3440]
char* GetData_007d3440()
{
    return &g_data_02c71314;
}
