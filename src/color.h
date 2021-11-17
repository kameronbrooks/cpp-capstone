#ifndef COLOR_H
#define COLOR_H
#include <iostream>


struct Color {
public:
    uint8_t data[4];
    uint8_t& r();
    uint8_t& g();
    uint8_t& b();
    uint8_t& a();

    uint8_t operator[](int i) const;
    uint8_t& operator[](int i);

    Color();
    Color(uint8_t r, uint8_t g,uint8_t b,uint8_t a);
    Color(int32_t col);
    Color(const Color& other);
    Color(Color&& other);
    ~Color();

    Color& operator=(const Color& other);
    Color& operator=(Color&& other);
};


#endif