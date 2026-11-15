// Packs a floating-point RGBA colour (components 0..1) into a 32-bit ARGB value.

struct FColorRGBAf
{
    float r;
    float g;
    float b;
    float a;

    unsigned int PackARGB() const;
};

extern const float g_fColorScale_009d9f84;

unsigned int FColorRGBAf::PackARGB() const
{
    unsigned int gi = (unsigned int)(int)(g * g_fColorScale_009d9f84) & 0xff;
    unsigned int ri = (unsigned int)(int)(r * g_fColorScale_009d9f84);
    unsigned int bi = (unsigned int)(int)(b * g_fColorScale_009d9f84) & 0xff;
    unsigned int ai = (unsigned int)(int)(g_fColorScale_009d9f84 * a) & 0xff;
    return (((ri << 8 | gi) << 8) | bi) << 8 | ai;
}
