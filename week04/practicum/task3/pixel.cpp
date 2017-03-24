#include "pixel.h"

Pixel Pixel::invert(const Pixel& p) {
    return Pixel {
        static_cast<uint8_t>(255 - p.red),
        static_cast<uint8_t>(255 - p.green),
        static_cast<uint8_t>(255 - p.blue),
    };
}
