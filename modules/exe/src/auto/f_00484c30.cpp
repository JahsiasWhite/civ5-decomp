// src: GUESS (confidence: low)
struct Obj_00484c30 {
    virtual void v0() = 0;
    virtual void v4() = 0;
    virtual void v8(int a, int b) = 0;
};

// src: GUESS (confidence: low)
struct Range_00484c30 {
    int start;
    int count;
};

// src: GUESS (confidence: low)
Obj_00484c30* fn_00484c30(Obj_00484c30* obj, const Range_00484c30* r) {
    int start = r->start;
    int count = r->count;
    for (int i = 0; i < count; ++i) {
        obj->v8(1, start + i);
    }
    return obj;
}
