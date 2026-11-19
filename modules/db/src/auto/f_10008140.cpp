#include "sqlite3_api.h"

namespace Database {

// src: GUESS (confidence: low)
struct Results_10008140
{
    void* m_vftable;
    void* m_conn;
    sqlite3_stmt* m_stmt;

    // src: EXE [0x10007e70]
    int ColumnPosition(const char* szColumn);
    // src: EXE [0x10008140]
    void GetValue(const char* szColumn, double& dValue);
};

void Results_10008140::GetValue(const char* szColumn, double& dValue)
{
    int col = ColumnPosition(szColumn);
    dValue = m_stmt ? sqlite3_column_double(m_stmt, col) : 0.0;
}

}
