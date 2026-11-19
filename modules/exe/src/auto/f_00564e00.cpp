// Maps a type id to its record size; 0 for unknown ids.

// src: GUESS (confidence: low) [0x00405390]
int GetRecordSize_00405390(int type)
{
    switch (type)
    {
    case 15:
        return 0x30;
    case 19:
        return 0x40;
    case 20:
        return 0x1c;
    case 24:
        return 0x38;
    default:
        return 0;
    }
}
