// Returns the file-name part of the stored path (after the last separator).
// The second search passes '//', a two-character literal, as in the
// original code.

#include <string.h>

// src: GUESS (confidence: low)
class PathHolder_0053a8f0
{
public:
    // src: GUESS (confidence: low) [0x0053a8f0]
    const char* GetFileName() const;

    char m_pad0[0x15c0];
    // src: GUESS (confidence: low)
    char m_path[260];
};

const char* PathHolder_0053a8f0::GetFileName() const
{
    const char* separator = strrchr(m_path, '\\');
    if (!separator)
        separator = strrchr(m_path, '//');
    if (!separator)
        return m_path;
    return separator + 1;
}
