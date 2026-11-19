// Returns 1 for 0, 0 for 1, and 0 for any value of 2 or more
// (negative values are XORed with 1).

int __stdcall InvertSmallFlag(int value)
{
    if (value < 2)
        return value ^ 1;
    return 0;
}
