
// Fill the range [first, last) of 32-bit values with *value (std::fill shape).
void FillUInt32Range(unsigned int* first, unsigned int* last, const unsigned int* value)
{
    for (; first != last; ++first)
        *first = *value;
}
