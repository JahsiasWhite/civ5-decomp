#include "Database/Results.h"

// src: GUESS (confidence: low)
struct UnkQuery_004b8320
{
    char m_pad[0x7c];
    Database::Results m_results;

    bool QueryBool_004b8320(const char* key);
};

// src: GUESS (confidence: medium) [0x004b8320]
bool UnkQuery_004b8320::QueryBool_004b8320(const char* key)
{
    m_results.Bind(1, key, true);
    m_results.Step();
    bool ret = m_results.GetBool(0);
    m_results.Reset();
    return ret;
}
