// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low) [0x00925cc0]
struct Data_00925cc0 {
    int d[5];
};

// src: GUESS (confidence: low) [0x00925cc0]
struct Class_00925cc0 {
    char pad[0x5c];
    Data_00925cc0 data;

    void CopyData(Data_00925cc0* out);
};

void Class_00925cc0::CopyData(Data_00925cc0* out) {
    *out = this->data;
}
