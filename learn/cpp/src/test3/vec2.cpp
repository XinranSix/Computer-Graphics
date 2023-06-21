/**
 * @file    :   vec2.cpp
 * @date    :   2023/06/21 12:29:10
 * @author  :   yaojie
 * @version :   1.0
 */

#include "vec2.h"
#include <cmath>

Vec2::Vec2() {}

Vec2::Vec2(double x, double y) : x(x), y(y) {}

Vec2::Vec2(const Vec2 &v) {
    x = v.x;
    y = v.y;
}

Vec2::~Vec2() {}

double Vec2::length() { return fsqrt(x * x + y * y); }

Vec2 &Vec2::operator=(const Vec2 &v) {
    x = v.x;
    y = v.y;
    return *this;
}

Vec2 &Vec2::operator+=(const Vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2 &Vec2::operator*=(const Vec2 &v) {
    x *= v.x;
    y *= v.y;
    return *this;
}

Vec2 &Vec2::operator/=(const Vec2 &v) {
    x /= v.x;
    y /= v.y;
    return *this;
}

Vec2 &Vec2::operator+() { return *this; }

Vec2 Vec2::operator-() { return Vec2{-x, -y}; }

Vec2 &Vec2::operator++() {
    x = x + 1;
    y = y + 1;
    return *this;
}

Vec2 Vec2::operator++(int) {
    Vec2 tmp{x, y};
    x = x + 1;
    y = y + 1;
    return tmp;
}

Vec2 &Vec2::operator--() {
    x = x - 1;
    y = y - 1;
    return *this;
}

Vec2 Vec2::operator--(int) {
    Vec2 tmp{x, y};
    x = x - 1;
    y = y - 1;
    return tmp;
}

Vec2 operator+(const Vec2 &v1, const Vec2 &v2) {
    return {v1.x + v2.x, v2.x + v2.y};
}

Vec2 operator-(const Vec2 &v1, const Vec2 &v2) {
    return {v1.x - v2.x, v2.x - v2.y};
}

Vec2 operator*(const Vec2 &v1, const Vec2 &v2) {
    return {v1.x * v2.x, v2.x * v2.y};
}

Vec2 operator/(const Vec2 &v1, const Vec2 &v2) {
    return {v1.x / v2.x, v2.x / v2.y};
}

bool operator==(const Vec2 &v1, const Vec2 &v2) {
    return fabs(v1.x - v2.x) < 0.01 && fabs(v1.y - v2.y);
}

bool operator!=(const Vec2 &v1, const Vec2 &v2) { return !(v1 == v2); }

std::ostream &operator<<(std::ostream &os, const Vec2 &v) {
    return os << v.x << ' ' << v.y;
}

std::istream &operator>>(std::istream &is, Vec2 &v) {
    is >> v.x >> v.y;
    return is;
}

int Vec2::operator[](std::size_t idx) {
    if (idx == 0) {
        return x;
    }
    if (idx == 1) {
        return y;
    }
    throw "下标越界";
}

const int Vec2::operator[](std::size_t idx) const {
    if (idx == 0) {
        return x;
    }
    if (idx == 1) {
        return y;
    }
    throw "下标越界";
}
