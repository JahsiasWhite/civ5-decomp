// c5d-cflags: -/EHsc
#include <memory>

// src: GUESS (confidence: low)
struct Obj_10002120 {
    // src: GUESS (confidence: low)
    virtual ~Obj_10002120() {}
};

// src: LIB [0x10002120]
std::auto_ptr<Obj_10002120>& (std::auto_ptr<Obj_10002120>::* Force_10002120)(std::auto_ptr_ref<Obj_10002120>) =
    &std::auto_ptr<Obj_10002120>::operator=;
