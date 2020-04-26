/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libMath"
 *
 * "libMath" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libMath" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libMath" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#ifndef LIB_MATH_VECTOR_VEC2_HPP
#define LIB_MATH_VECTOR_VEC2_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

struct vec2
{
    static const uint32_t SIZE = 2;
    vec2(float64 _f) { x = _f; y = _f; }
    vec2(float64 _x, float64 _y) { x = _x; y = _y; }
    ~vec2(void) { }
    vec2(const vec2& _v) { x = _v.x; y = _v.y; }
    bool operator==(const vec2& _v) { return (x == _v.x && y == _v.y); }
    vec2& operator=(const vec2& _v) { x = _v.x; y = _v.y; return *this; }
    void operator+=(const vec2& _v) { x += _v.x; y += _v.y; }
    vec2 operator+(const vec2& _v) const { return vec2(x + _v.x, y + _v.y); }
    void operator-=(const vec2& _v) { x -= _v.x; y -= _v.y; }
    vec2 operator-(const vec2& _v) const { return vec2(x - _v.x, y - _v.y); }
    void operator*=(const float64 _s) { x *= _s; y *= _s; }
    vec2 operator*(const float64 _s) const {    return vec2(_s * x, _s * y); }
    void operator /=(const float64 _s) { x /= _s; y /= _s; }
    vec2 operator/(const float64 _s) const {return vec2(x / _s, y / _s); }
    float64 operator*(const vec2& _v) const { return x * _v.x + y * _v.y; }
    float64 dot(const vec2& _v) const { return x * _v.x + y * _v.y; }
    float64 magnitude(void){ return std::sqrt(x * x + y * y); }
    void normalize(void) { float64 magnitude = std::sqrt(x * x + y * y); if (magnitude > 0.0f) { float64 oneOverMagnitude = 1.0f / magnitude; x = x * oneOverMagnitude; y = y * oneOverMagnitude; } }

    union
    {
        struct { float64 x = 0.0f; float64 y = 0.0f; };
        struct { float64 array[SIZE]; };
    };
};

#endif // LIB_MATH_VECTOR_VEC2_HPP