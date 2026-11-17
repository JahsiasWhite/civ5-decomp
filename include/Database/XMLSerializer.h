// Database::XMLSerializer: loads the game's XML data files into the SQLite database.
// Layout from the DLL's code (offsets below); names follow the SDK.
#pragma once
#include "DatabaseAPI.h"

namespace Database {

class XMLSerializer {
public:
    CVGAMEDATABASE_API const char* ErrorMessage() const;

    CVGAMEDATABASE_API bool UseTransactions() const;
    CVGAMEDATABASE_API void UseTransactions(bool bUse);

private:
    char m_szCurrentFileName[256];     // +0x000
    char m_szErrorMessage[512];        // +0x100
    Connection& m_db;                  // +0x300
    char* m_pkFileBuffer;              // +0x304
    unsigned int m_lenFileBuffer;      // +0x308
    bool m_bUseTransactions;           // +0x30c
    // +0x310: package tag table list and package tag (not modelled yet)
};

}  // namespace Database
