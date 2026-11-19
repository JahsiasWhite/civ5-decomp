#include "sqlite3_api.h"

namespace Database {

// src: GUESS (confidence: low)
struct Results_100080f0
{
    void* m_vftable;
    void* m_conn;
    sqlite3_stmt* m_stmt;

    // src: EXE [0x10007e70]
    int ColumnPosition(const char* szColumn);
    // src: EXE [0x100080f0]
    void GetValue(const char* szColumn, float& fValue);
};

void Results_100080f0::GetValue(const char* szColumn, float& fValue)
{
    int col = ColumnPosition(szColumn);
    fValue = m_stmt ? (float)sqlite3_column_double(m_stmt, col) : 0.0f;
}

}
