// Reads the file's last-write time.

#include <windows.h>

// src: GUESS (confidence: low)
class File_00820940
{
public:
    // src: GUESS (confidence: low) [0x00820940]
    void GetWriteTime(FILETIME* out) const;

    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    HANDLE m_handle;
};

void File_00820940::GetWriteTime(FILETIME* out) const
{
    FILETIME writeTime;
    GetFileTime(m_handle, NULL, NULL, &writeTime);
    *out = writeTime;
}
