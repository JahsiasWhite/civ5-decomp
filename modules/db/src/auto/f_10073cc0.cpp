// c5d-cflags: -/EHsc /GS-
#include <cstdlib>
#include <list>
#include <string>

// src: GUESS (confidence: low)
struct XMLSerializer_10073cc0
{
    char m_szCurrentFileName[256];
    char m_szErrorMessage[512];
    void* m_db;
    char* m_pkFileBuffer;
    unsigned int m_lenFileBuffer;
    bool m_bUseTransactions;
    std::list<std::string> m_packageTagList;
    std::string m_strPackageTag;

    // src: GUESS (confidence: high) [0x10073cc0]
    ~XMLSerializer_10073cc0();
};

XMLSerializer_10073cc0::~XMLSerializer_10073cc0()
{
    free(m_pkFileBuffer);
}
