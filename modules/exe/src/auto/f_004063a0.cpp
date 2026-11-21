// Returns the message text of a bad-allocation error. The string is a literal in
// the game's read-only data, and the function returns its address.

// src: GUESS (confidence: low) [0x004063a0]
const char* GetBadAllocMessage_004063a0()
{
    return "bad allocation in previous or concurrent attempt";
}
