// Depends on the project-wide _SECURE_SCL=0 / _HAS_EXCEPTIONS=0 (config.json):
// without them _Uninit_copy keeps a try/catch and isn't inlined here.
//
// std::vector<T>::_Umove for a vector of one-byte, non-scalar elements:
// copy-constructs [first, last) into the new storage at dest (the inlined
// _Uninit_copy loop) and returns the end of the copied range. Identical
// instantiations from several vector types are folded onto this address.

#include <vector>

struct ByteCell
{
    char value;
};

// Stand-in for the vector reserve paths (0x622480 and friends) that call
// _Umove; only here so _Umove<ByteCell> is instantiated.
void ReserveByteCells(std::vector<ByteCell> &cells, size_t count)
{
    cells.reserve(count);
}
