// Fills the range [first, last) with copies of *value (std::fill for 32-bit elements).

void FillDwordRange(unsigned int* first, unsigned int* last, const unsigned int& value)
{
    for (; first != last; ++first)
        *first = value;
}
