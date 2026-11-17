// The standard library's raise hook for an exception class, built with
// exceptions turned off (_HAS_EXCEPTIONS=0): it hands the object to
// std::_Throw. Eight exception classes share this one folded body.

#include <exception>

// src: GUESS (confidence: low)
class RaisedError_00646bc0 : public std::exception
{
protected:
    // src: LIB [0x00646bc0]
    virtual void _Doraise() const;
};

void RaisedError_00646bc0::_Doraise() const
{
    _RAISE(*this);
}
