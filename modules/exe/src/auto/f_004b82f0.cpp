#include "Database/Connection.h"
#include "Database/Results.h"

// src: GUESS (confidence: low) [0x004b82f0]
struct Unk_004b82f0
{
    Database::Connection m_conn;  // +0x00
    Database::Results m_res7c;    // +0x7c
    Database::Results m_resbc;    // +0xbc

    // src: GUESS (confidence: high) [0x004b82f0]
    bool Shutdown_004b82f0();
};

// src: GUESS (confidence: high) [0x004b82f0]
bool Unk_004b82f0::Shutdown_004b82f0()
{
    m_res7c.Release();
    m_resbc.Release();
    m_conn.Close();
    return true;
}
