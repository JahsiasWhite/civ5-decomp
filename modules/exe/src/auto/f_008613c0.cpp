// Erases [first, last) from the object's vector; returns the position after
// the erased range.

#include <vector>

// src: GUESS (confidence: low)
struct Value_008e5fd0
{
    int m_value;
};

// src: GUESS (confidence: low)
class Values_008e5fd0
{
public:
    typedef std::vector<Value_008e5fd0>::iterator iterator;

    // src: GUESS (confidence: low) [0x008e5fd0]
    iterator Erase(iterator first, iterator last);

    // src: GUESS (confidence: low)
    std::vector<Value_008e5fd0> m_values;
};

Values_008e5fd0::iterator Values_008e5fd0::Erase(iterator first, iterator last)
{
    return m_values.erase(first, last);
}
