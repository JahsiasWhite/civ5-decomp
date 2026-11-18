// Maps a level to a tier: below 3 is 1, 3 is 2, 4 is 3, 5 and up is 4.

// src: GUESS (confidence: low) [0x007ac8d0]
int GetTier_007ac8d0(int level)
{
    int tier = 0;
    if (level < 3)
        tier = 1;
    else if (level == 3)
        tier = 2;
    else if (level == 4)
        tier = level - 1;
    else if (level >= 5)
        tier = 4;
    return tier;
}
