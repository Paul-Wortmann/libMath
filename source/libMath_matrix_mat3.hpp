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

#ifndef LIB_MATH_MATRIX_MAT3_HPP
#define LIB_MATH_MATRIX_MAT3_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"
#include "libMath_vector.hpp"

struct mat3
{
    //--- Column major! ---
    static const uint32_t COLUMNS = 3;
    static const uint32_t ROWS    = 3;
    mat3(void) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (i == j) ? 1.0f : 0.0f;}
    mat3(int _s) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (_s == 1) ? (i == j) ? 1.0f : 0.0f : _s; }
    mat3(float64 _f) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = _f; }
    mat3(float64 _f00, float64 _f10, float64 _f20,
         float64 _f01, float64 _f11, float64 _f21,
         float64 _f02, float64 _f12, float64 _f22)
         {
             data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02;
             data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12;
             data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22;
         }
    ~mat3(void) { }
    mat3& operator=(const mat3& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _m.array[i]; return *this; }
    mat3 operator+(const mat3& _m) const { mat3 _tMat3; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat3.array[i] = _m.array[i] + array[i]; return _tMat3; }
    void operator+=(const mat3& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] += _m.array[i]; }
    mat3 operator-(const mat3& _m) const { mat3 _tMat3; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat3.array[i] = _m.array[i] - array[i]; return _tMat3; }
    void operator-=(const mat3& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] -= _m.array[i]; }
    mat3 operator*(const float64 _s) const { mat3 _tMat3; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat3.array[i] = array[i] * _s; return _tMat3; }
    void operator*=(const float64 _s) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] *= _s; }
    mat3 operator*(const mat3& _m) const { mat3 _tMat3(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat3.data[i][j] += data[i][k] * _m.data[k][j]; } } } return _tMat3; }
    void operator*=(const mat3& _m) { mat3 _tMat3(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat3.data[i][j] += data[i][k] * _m.data[k][j]; } } } for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _tMat3.array[i]; }
    vec3 operator*(const vec3& _v) const 
    { 
        vec3 _tVec3(0.0f); 
        for(size_t i = 0; i < ROWS; i++) 
        { 
            for(size_t j = 0; j < COLUMNS; j++)
            {
                _tVec3.array[i] += data[i][j] * _v.array[j];
            }
        }
        return _tVec3;
    }

    float64 determinant(void)
    {
        float64 det = 0;
        det += data[0][0] * ((data[1][1] * data[2][2]) - (data[1][2] * data[2][1]));
        det += data[0][1] * ((data[1][2] * data[2][0]) - (data[1][0] * data[2][2]));
        det += data[0][2] * ((data[1][0] * data[2][1]) - (data[1][1] * data[2][0]));
        return det;
    }

    void transpose(void)
    {
        for(size_t i = 0; i < ROWS; i++)
        {
            for(size_t j = i; j < COLUMNS; j++)
            {
                if (i != j)
                {
                    float64 temp = data[j][i];
                    data[j][i] = data[i][j];
                    data[i][j] = temp;
                }
            }
        }
    }

    void setCR(float64 _f00, float64 _f10, float64 _f20,
               float64 _f01, float64 _f11, float64 _f21,
               float64 _f02, float64 _f12, float64 _f22)
               {
                   data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02;
                   data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12;
                   data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22;
               }
    
    void setRC(float64 _f00, float64 _f01, float64 _f02,
               float64 _f10, float64 _f11, float64 _f12,
               float64 _f20, float64 _f21, float64 _f22)
               {
                   data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02;
                   data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12;
                   data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22;
               }

    union
    {
        struct { float64 array[COLUMNS * ROWS] = {0.0f}; };
        struct { float64 data[COLUMNS][ROWS]; };
    };

/*  -- internal test code ---
    void draw(void)
    {
        std::cout << "--- mat3 ---" << std::endl;
        for (size_t i = 0; i < COLUMNS * ROWS; i++)
        {
            std::cout << "[" << array[i] << "]";
            if ((i % ROWS) == (COLUMNS-1))
            std::cout << std::endl;
        }
        std::cout << "--------" << std::endl;
    }
*/

};

#endif // LIB_MATH_MATRIX_MAT3_HPP