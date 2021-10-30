#include "color.h"

Color::Color() {
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
}
Color::Color(uint8_t r, uint8_t g,uint8_t b,uint8_t a) {
    data[0] = r;
    data[1] = g;
    data[2] = b;
    data[3] = a;
}
Color::Color(int32_t col) {
    data[0] = col & 255;
    data[1] = (col & (255 << 8)) >> 8;
    data[2] = (col & (255 << 16)) >> 16;
    data[3] = (col & (255 << 24)) >> 24;
}
Color::Color(const Color& other) {
    data[0] = other.data[0];
    data[1] = other.data[1];
    data[2] = other.data[2];
    data[3] = other.data[3];

}
Color::Color(Color&& other) {
    data[0] = other.data[0];
    data[1] = other.data[1];
    data[2] = other.data[2];
    data[3] = other.data[3];
}

uint8_t& Color::r(){
    return data[0];
}
uint8_t& Color::g(){
    return data[1];
}
uint8_t& Color::b(){
    return data[2];
}
uint8_t& Color::a(){
    return data[3];
}

uint8_t Color::operator[](int i) const {
    return data[i];
}
uint8_t& Color::operator[](int i) {
    return data[i];
}

Color& Color::operator=(const Color& other) {
    data[0] = other.data[0];
    data[1] = other.data[1];
    data[2] = other.data[2];
    data[3] = other.data[3];
}
Color& Color::operator=(Color&& other) {
    data[0] = other.data[0];
    data[1] = other.data[1];
    data[2] = other.data[2];
    data[3] = other.data[3];
}