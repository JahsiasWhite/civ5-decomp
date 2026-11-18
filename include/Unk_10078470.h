// c5d-vtable: 0x10078470
#pragma once
#include <exception>

// src: GUESS (confidence: low)
class Unk_10078470 : public stdext::exception {
public:
    virtual ~Unk_10078470();
    virtual const char* what() const;
    // src: GUESS 0x10001150 (confidence: high)
    virtual void _Doraise() const;
};
