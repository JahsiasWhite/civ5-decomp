// Erases [first, last) from the object's int vector; returns the position
// after the erased range.

#include <vector>

// src: GUESS (confidence: low)
struct Value_00622080
{
    int m_value;
};

// src: GUESS (confidence: low)
class Values_00622080
{
public:
    typedef std::vector<Value_00622080>::iterator iterator;

    // src: GUESS (confidence: low) [0x00622080]
    iterator Erase(iterator first, iterator last);

    // src: GUESS (confidence: low)
    std::vector<Value_00622080> m_values;
};

Values_00622080::iterator Values_00622080::Erase(iterator first, iterator last)
{
    return m_values.erase(first, last);
}
