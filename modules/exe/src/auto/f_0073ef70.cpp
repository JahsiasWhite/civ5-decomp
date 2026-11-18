// Runs the Lua "PreGameStart" hook, then carries on with the game start.

#include "ICvEngineUtility1.h"

// src: GUESS (confidence: low)
struct EngineOwner_00cc8e74
{
    // src: GUESS (confidence: low)
    char m_pad0000[0x1460];
    // src: GUESS (confidence: medium)
    ICvEngineUtility1* m_pEngineUtility;
};

// src: GUESS (confidence: low)
extern EngineOwner_00cc8e74* g_pEngineOwner_00cc8e74;

// src: GUESS (confidence: low)
class GameStarter_0073ef70
{
public:
    // src: GUESS (confidence: medium) [0x0073ef70]
    void PreGameStart();
    // src: GUESS (confidence: low) [0x006d5c30]
    void Continue_006d5c30();
};

void GameStarter_0073ef70::PreGameStart()
{
    ICvEngineScriptSystem1* pkScriptSystem = g_pEngineOwner_00cc8e74->m_pEngineUtility->GetScriptSystem();
    if (pkScriptSystem != 0)
    {
        bool bResult;
        pkScriptSystem->CallHook("PreGameStart", 0, bResult);
    }
    Continue_006d5c30();
}
