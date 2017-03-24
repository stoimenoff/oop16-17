#include "bmp.h"

/**
 *  Конструктор на класа Bmp
 *
 *  В C++ конструкторите винаги трябва да връщат валиден обект.
 *  Но това е проблематично, когато създаването на обекта може да се провали
 *  поради причини, които не зависят от програмата ни. В случая това може да са:
 *      - подадения файл не съществува
 *      - подадения файл съществува, но не е BMP изображение
 *      - подаденият файл е валидно BMP изображение, но използва опции които не поддържаме.
 *
 *  Обещали сме, всички обекти от класа ще са валидни (следва от RAII принципа), поради което не
 *  можем да върнем невалиден обект.
 *
 *  В C++ стандартното решение в такъв случай е конструктора да хвърля грешка (exception).
 *  Но за да не навлизаме в материала за изключения аз просто ще прекратявам програмата с `exit`.
 */
Bmp::Bmp(const char* filename) :
    pixelArray(NULL)
{
    this->file = fstream(filename, ios::in | ios::out | ios::binary);
    if (!this->file.is_open()) {
        cerr << "Could not open file\n";
        exit(1);
    };

    // Внимание - control ни е масив от два char-a, но не е низ, защото няма терминираща нула.
    // На нас не ни е необходим низ, защото просто искаме да сравним два char-а.
    char control[2];
    this->file.read(control, 2);
    if (control[0] != 'B' || control[1] != 'M') {
        cerr << "Incorrect file format\n";
        exit(1);
    }

    // За да прочетем информацията от bmp header-a процедираме по следния начин:
    //      - използваме seekg за да се отместим на правилната позиция във файла
    //      - прочитаме толкова байта, колкото ни трябват. Използваме uint*_t типовете за това.

    this->file.seekg(10);
    this->file.read(reinterpret_cast<char*>(&this->dataOffset), sizeof(this->dataOffset));

    this->file.seekg(18);
    this->file.read(reinterpret_cast<char*>(&this->width), sizeof(this->width));
    this->file.read(reinterpret_cast<char*>(&this->height), sizeof(this->height));
    if (this->width % 4 != 0) {
        cerr << "Image width must be multiple of 4\n";
        exit(1);
    }

    size_t len = this->width * this->height;
    this->pixelArray = new Pixel[len];
    this->file.seekg(this->dataOffset);
    this->file.read(reinterpret_cast<char*>(this->pixelArray), len * sizeof(Pixel));
}

Bmp::~Bmp() {
    this->save();
    delete[] this->pixelArray;
}

void Bmp::negative() {
    size_t len = this->width * this->height;
    for (size_t i = 0; i < len; i++) {
        this->pixelArray[i] = Pixel::invert(this->pixelArray[i]);
    }
}

uint32_t Bmp::getWidth() const {
    return this->width;
}

uint32_t Bmp::getHeight() const {
    return this->height;
}

const Pixel& Bmp::getPixel(uint32_t x, uint32_t y) const {
    return this->pixelArray[y * this->width + x];
}

void Bmp::setPixel(uint32_t x, uint32_t y, const Pixel& pixel) {
    this->pixelArray[y * this->width + x] = pixel;
}

void Bmp::save() {
    size_t len = this->width * this->height;
    this->file.seekg(this->dataOffset);
    this->file.write(reinterpret_cast<char*>(this->pixelArray), len * sizeof(Pixel));
}
