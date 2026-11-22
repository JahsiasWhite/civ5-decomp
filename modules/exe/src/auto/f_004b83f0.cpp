#include "Database/Connection.h"

// src: GUESS (confidence: high)
struct Unk_004b83f0 : public Database::Connection {
    // src: EXE [0x004b83f0]
    void ClearAdvisorMessagesViewed() const;
};

void Unk_004b83f0::ClearAdvisorMessagesViewed() const {
    Execute("DELETE FROM AdvisorMessagesViewed", -1);
}
