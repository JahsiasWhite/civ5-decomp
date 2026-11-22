// Returns the message text used when a structured task group is destroyed or
// used without wait() having been called. The string is a literal in the game's
// read-only data, and the function returns its address.

// src: GUESS (confidence: low) [0x004063b0]
const char* GetWaitNotCalledMessage_004063b0()
{
    return "wait() was not called on the structured_task_group";
}
