// c5d-cflags: -/EHsc
#include <exception>
#include <string>

// src: GUESS (confidence: low)
class Unk_1007847c_G : public stdext::exception {
public:
    // src: GUESS 0x10001220 (confidence: medium)
    virtual ~Unk_1007847c_G() {}

private:
    // src: GUESS (confidence: medium)
    std::string m_message;
};

// src: GUESS (confidence: low)
Unk_1007847c_G* CreateUnk_10001220() {
    return new Unk_1007847c_G();
}
