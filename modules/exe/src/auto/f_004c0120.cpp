// src: GUESS (confidence: low) [0x0041b9e0]
struct Vec3_0041b9e0 {
    int x;
    int y;
    int z;

    int NotEqual(const Vec3_0041b9e0* other);
};

int Vec3_0041b9e0::NotEqual(const Vec3_0041b9e0* other) {
    if (this->x != other->x || this->y != other->y || this->z != other->z) {
        return 1;
    }
    return 0;
}
