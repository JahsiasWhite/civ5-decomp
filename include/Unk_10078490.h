// c5d-vtable: 0x10078490
#pragma once
#include <exception>

// src: GUESS (confidence: low)
class Unk_10078490 : public stdext::exception {
public:
    virtual ~Unk_10078490();
    virtual const char* what() const;
    // src: GUESS 0x100012a0 (confidence: high)
    virtual void _Doraise() const;
};
