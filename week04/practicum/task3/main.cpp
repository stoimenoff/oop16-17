/**
 *  Примерно решение на задача 3 от седмица 4
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
}
