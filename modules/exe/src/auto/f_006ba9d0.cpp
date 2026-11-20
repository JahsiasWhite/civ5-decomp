// src: GUESS (confidence: low)
struct UnkPair8_006ba9d0
{
    int a;
    int b;
};

// src: GUESS (confidence: medium) [0x006ba9d0]
void FillPair8_006ba9d0(UnkPair8_006ba9d0* first, UnkPair8_006ba9d0* last, const UnkPair8_006ba9d0& val)
{
    for (; first != last; ++first)
        *first = val;
}
