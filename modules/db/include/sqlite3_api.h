// The parts of SQLite's C API (3.7.17) the database DLL's own code calls. SQLite is
// compiled into the DLL and is out of scope here (modules/db/scope_overrides.txt); its
// functions are named in modules/db/symbols/sqlite.txt so calls to them can be checked.
#pragma once

struct sqlite3;
struct sqlite3_stmt;

extern "C" {
int sqlite3_total_changes(sqlite3* db);
const char* sqlite3_errmsg(sqlite3* db);
int sqlite3_errcode(sqlite3* db);
int sqlite3_column_count(sqlite3_stmt* pStmt);
const char* sqlite3_column_name(sqlite3_stmt* pStmt, int N);
int sqlite3_column_int(sqlite3_stmt* stmt, int iCol);
const unsigned char* sqlite3_column_text(sqlite3_stmt* stmt, int iCol);
const void* sqlite3_column_text16(sqlite3_stmt* stmt, int iCol);
int sqlite3_bind_null(sqlite3_stmt* pStmt, int iCol);
int sqlite3_bind_int(sqlite3_stmt* pStmt, int iCol, int iValue);
}
