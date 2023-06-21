/**
 * @file    :   vec2.h
 * @date    :   2023/06/21 12:11:34
 * @author  :   yaojie
 * @version :   1.0
 */

#ifndef VEC2_H
#define VEC2_H

#include <iostream>

class Vec2 {
public:
    Vec2();
    Vec2(double x, double y);
    Vec2(const Vec2 &v);
    ~Vec2();

public:
    double length();

public:
    Vec2 &operator=(const Vec2 &v);
    Vec2 &operator+=(const Vec2 &v);
    Vec2 &operator-=(const Vec2 &v);
    Vec2 &operator*=(const Vec2 &v);
    Vec2 &operator/=(const Vec2 &v);

    Vec2 &operator+();
    Vec2 operator-();
    Vec2 &operator++();
    Vec2 operator++(int);
    Vec2 &operator--();
    Vec2 operator--(int);

    int operator[](std::size_t idx);
    const int operator[](std::size_t idx) const;

    friend Vec2 operator+(const Vec2 &v1, const Vec2 &v2);
    friend Vec2 operator-(const Vec2 &v1, const Vec2 &v2);
    friend Vec2 operator*(const Vec2 &v1, const Vec2 &v2);
    friend Vec2 operator/(const Vec2 &v1, const Vec2 &v2);

    friend bool operator==(const Vec2 &v1, const Vec2 &v2);
    friend bool operator!=(const Vec2 &v1, const Vec2 &v2);

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &v);
    friend std::istream &operator>>(std::istream &is, Vec2 &v);

private:
    double x;
    double y;
};

#endif