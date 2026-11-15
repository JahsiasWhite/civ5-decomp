// c5d-model: claude-opus-5-5
// Case-insensitive comparison of a held C string against another string.

#include <string.h>

struct CaseInsensitiveStringKey
{
    const char* str;

    int CompareNoCase(const char* other) const;
};

int CaseInsensitiveStringKey::CompareNoCase(const char* other) const
{
    return _stricmp(str, other);
}
