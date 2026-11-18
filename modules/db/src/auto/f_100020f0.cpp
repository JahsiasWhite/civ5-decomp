// c5d-cflags: -/EHsc +/Ob0
#include <ostream>

// src: LIB [0x100020f0]
void SentryDtorForce_100020f0(std::basic_ostream<char>& os) {
    std::basic_ostream<char>::_Sentry_base s(os);
}
