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

#ifndef LIB_MATH_VECTOR_VEC3_HPP
#define LIB_MATH_VECTOR_VEC3_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

struct vec3
{
    // data structures, variables and constants
    static const uint32_t SIZE = 3; // vec3 == 3
    union
    {
        struct { float64 x = 0.0; float64 y = 0.0; float64 z = 0.0; };
        struct { float64 array[SIZE]; };
    };
    
    // construnctors and destructor
    vec3(void) { this->x = 0.0; this->y = 0.0; this->z = 0.0; }
    vec3(const float64 &_f) { this->x = _f; this->y = _f; this->z = _f; }
    vec3(const float64 &_x, const float64 &_y, const float64 &_z) { this->x = _x; this->y = _y; this->z = _z; }
    vec3(const vec3& _v) { this->x = _v.x; this->y = _v.y; this->z = _v.z; }
    ~vec3(void) = default;
    
    // opperators
    bool operator==(const vec3& _v) const { return (this->x == _v.x && this->y == _v.y && this->z == _v.z); }
    vec3& operator=(const vec3& _v) { this->x = _v.x; this->y = _v.y; this->z = _v.z; return *this; }
    vec3 operator- (void) const { vec3 v(-this->x, -this->y, -this->z); return v; }
    void operator+=(const vec3& _v) { this->x += _v.x; this->y += _v.y; this->z += _v.z; }
    vec3 operator+(const vec3& _v) const { return vec3(this->x + _v.x, this->y + _v.y, this->z + _v.z); }
    void operator-=(const vec3& _v) { this->x -= _v.x; this->y -= _v.y; this->z -= _v.z; }
    vec3 operator-(const vec3& _v) const { return vec3(this->x - _v.x, this->y - _v.y, this->z - _v.z); }
    void operator*=(const float64 _s) { this->x *= _s; this->y *= _s; this->z *= _s; }
    vec3 operator*(const float64 _s) const {    return vec3(_s * this->x, _s * this->y, _s * this->z); }
    void operator /=(const float64 _s) { this->x /= _s; this->y /= _s; this->z /= _s; }
    vec3 operator/(const float64 _s) const {return vec3(this->x / _s, this->y / _s, this->z / _s); }
    float64 operator*(const vec3& _v) const { return this->x * _v.x + this->y * _v.y + this->z * _v.z; }
    void operator %=(const vec3& _v) { *this=cross(_v); }
    vec3 operator %(const vec3& _v) const { return vec3(this->y * _v.z - this->z * _v.y, this->z * _v.x - this->x * _v.z, this->x * _v.y - this->y * _v.x); }

    friend vec3 operator+ (const float64 &_vl, const vec3 &_vr) { vec3 v(_vl + _vr.x, _vl + _vr.y, _vl + _vr.z); return v; }
    friend vec3 operator- (const float64 &_vl, const vec3 &_vr) { vec3 v(_vl - _vr.x, _vl - _vr.y, _vl - _vr.z); return v; }
    friend vec3 operator* (const float64 &_vl, const vec3 &_vr) { vec3 v(_vl * _vr.x, _vl * _vr.y, _vl * _vr.z); return v; }
    friend vec3 operator/ (const float64 &_vl, const vec3 &_vr) { vec3 v(_vl / _vr.x, _vl / _vr.y, _vl / _vr.z); return v; }

    // functions
    float64 length(void){ return std::sqrt((x * x) + (y * y) + (z * z)); }
    float64 magnitude(void){ return std::sqrt((x * x) + (y * y) + (z * z)); }
    void normalize(void) { float64 l = length(); if (l > 0.0) { float64 il = 1.0 / length(); x = x * il; y = y * il; z = z * il; } };
    vec3 normalized(void) { float64 l = length(); return (l > 0.0) ? (vec3(x, y, z) * (1.0 / l)) : vec3(x, y, z); }
    float64 distance(const vec3 &_v) const { return std::sqrt(((x - _v.x) * (x - _v.x)) + ((y - _v.y) * (y - _v.y)) + ((z - _v.z) * (z - _v.z))); }
    float64 dot(const vec3& _v) const { return x * _v.x + y * _v.y + z * _v.z; }
    vec3 cross(const vec3& _v) const { return vec3( y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x); }

    static float64 dot(const vec3 &_v1, const vec3 &_v2) { float64 s = (_v1.x * _v2.x) + (_v1.y * _v2.y) + (_v1.z * _v2.z); return s; }
    static vec3 cross(const vec3 &_v1, const vec3 &_v2) { vec3 v((_v1.y * _v2.z) - (_v1.z * _v2.y), (_v1.z * _v2.x) - (_v1.x * _v2.z), (_v1.x * _v2.y) - (_v1.y * _v2.x)); return v; }
};

#endif // LIB_MATH_VECTOR_VEC3_HPP