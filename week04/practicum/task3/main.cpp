/**
 *  Примерно решение на задача 3 от седмица 4 - прилагане на филтри върху BMP изображение
 *  Автор: Никола Стоянов
 */

#include <iostream>
#include "bmp.h"
#include "pixel.h"

using std::cin;

int main() {
    const int MAX_FILENAME = 255;
    char filename[MAX_FILENAME];

    cin.getline(filename, MAX_FILENAME);

    Bmp bmp(filename);
    bmp.negative();

    // тука обектът `bmp` се унищожава, при което нашите промени се запазват на диска
}
