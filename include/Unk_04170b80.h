#pragma once

// Placeholder: the global table of 0x398-byte records at 0x04170b80 and its
// count at 0x0413e300. 0x008bc860 reads the int at 0x394 of each record (it
// declares its own view of the same table). Rename once the type is known.

// src: GUESS (confidence: low) [0x04170b80]
struct UnkRecord398_04170b80
{
    char m_data[0x398];
};

// src: GUESS (confidence: low) [0x0413e300]
extern unsigned int g_recordCount_0413e300;
// src: GUESS (confidence: low) [0x04170b80]
extern UnkRecord398_04170b80 g_records_04170b80[];
