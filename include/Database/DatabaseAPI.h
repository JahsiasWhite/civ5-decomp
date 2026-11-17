// CvGameDatabase DLL: export/import of its classes.
//
// The DLL's own sources (modules/db/src) define CVGAMEDATABASE_API as
// __declspec(dllexport) before including any Database header; everything else (the
// exe, the localization DLL) sees __declspec(dllimport), which is how the shipped
// binaries call into it.
#pragma once

#ifndef CVGAMEDATABASE_API
#define CVGAMEDATABASE_API __declspec(dllimport)
#endif

struct sqlite3;
struct sqlite3_stmt;

namespace Database {
class Connection;
}
