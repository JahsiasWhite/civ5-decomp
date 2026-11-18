// Maps a mode (1, 2, 3) to its size (2, 4, 8); anything else is 1.

// src: GUESS (confidence: low) [0x005efb40]
int GetModeSize_005efb40(int mode)
{
    switch (mode)
    {
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    default:
        return 1;
    }
}
