// c5d-cflags: -/EHsc   (no unwind frame for the member destructors)
// Destroys a record of six strings.

#include <string>

// src: GUESS (confidence: low)
struct StringSet_0071b500
{
    // src: GUESS (confidence: low) [0x0071b500]
    ~StringSet_0071b500();

    // src: GUESS (confidence: low)
    std::string m_00;
    // src: GUESS (confidence: low)
    std::string m_1c;
    // src: GUESS (confidence: low)
    std::string m_38;
    // src: GUESS (confidence: low)
    std::string m_54;
    // src: GUESS (confidence: low)
    std::string m_70;
    // src: GUESS (confidence: low)
    std::string m_8c;
};

StringSet_0071b500::~StringSet_0071b500()
{
}
