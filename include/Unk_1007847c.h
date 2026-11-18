// c5d-vtable: 0x1007847c
#pragma once
#include <exception>
#include <string>

// src: GUESS (confidence: low)
class Unk_1007847c : public stdext::exception {
public:
    // src: GUESS 0x100011e0 (confidence: high)
    virtual ~Unk_1007847c();
    virtual const char* what() const;
    virtual void _Doraise() const;

private:
    // src: GUESS (confidence: medium)
    std::string m_message; // +0x08
};
