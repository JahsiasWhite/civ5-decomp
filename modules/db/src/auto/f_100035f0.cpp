// c5d-cflags: -/EHsc +/GS-
#define CVGAMEDATABASE_API __declspec(dllexport)
#include "Database/Connection.h"
#include "Database/Results.h"
#include "sqlite3_api.h"

extern "C" {
char* sqlite3_snprintf(int, char*, const char*, ...);
}

// src: GUESS [0x10002c20] (confidence: high)
bool PrepareCommand_10002c20(Database::Command* pCmd, const char* szSQL, int iLength);
// src: GUESS [0x10002ce0] (confidence: high)
void FinalizeCommand_10002ce0(Database::Command* pCmd);

// src: GUESS (confidence: low)
class ResultsExt_10007bd0 {
public:
    // src: GUESS [0x10007bd0] (confidence: high)
    bool SetCommand(const Database::Command& cmd);
};

namespace Database {

// src: EXE [0x100035f0]
bool Connection::SelectAt(Results& kResults, const char* szTable, const char* szColumn, const char* szValue) {
    Command cmd = { this, 0 };
    char szSQL[1024] = { 0 };
    const char* szLimit = kResults.SingleQuery() ? "LIMIT 1" : "";
    const char* szPrepared = sqlite3_snprintf(
        1024, szSQL, "select %s from %q where %s = %Q %s",
        kResults.GetColumns(), szTable, szColumn, szValue, szLimit);
    if (PrepareCommand_10002c20(&cmd, szPrepared, -1)) {
        return reinterpret_cast<ResultsExt_10007bd0*>(&kResults)->SetCommand(cmd);
    }
    FinalizeCommand_10002ce0(&cmd);
    return false;
}

}  // namespace Database
