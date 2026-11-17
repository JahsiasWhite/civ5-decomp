// CvLocalization DLL: export/import of its classes and functions.
//
// The DLL's own sources (modules/loc/src) define CVLOCALIZATION_API as
// __declspec(dllexport) before including any Localization header; everything else
// (the exe) sees __declspec(dllimport).
#pragma once

#ifndef CVLOCALIZATION_API
#define CVLOCALIZATION_API __declspec(dllimport)
#endif

namespace Localization {
class IPluralityRule;
class ParameterTransforms;
}
