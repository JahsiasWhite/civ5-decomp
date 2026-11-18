// c5d-cflags: -/EHsc
#include <exception>
#include <string>

// src: GUESS (confidence: low)
class Unk_100012b0 : public stdext::exception {
public:
    // src: GUESS 0x100012b0 (confidence: medium)
    virtual ~Unk_100012b0() {}

private:
    // src: GUESS (confidence: medium)
    std::string m_message;
};

// src: GUESS (confidence: low)
Unk_100012b0* CreateUnk_100012b0() {
    return new Unk_100012b0();
}
