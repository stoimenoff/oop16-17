#ifndef __PIXEL_H__
#define __PIXEL_H__

#include <cstdint>

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    static Pixel invert(const Pixel& p);
};

#endif
