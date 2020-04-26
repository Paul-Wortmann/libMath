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

#include "libMath_defines.hpp"
#include "libMath_matrix.hpp"
#include "libMath_vector.hpp"

mat4 translate(const mat4 &_mat4, const vec4 &_transVec);
mat4 translate(const vec4 &_transVec);
mat4 scale(const mat4 &_mat4, const vec4 &_scaleVec);
mat4 scale(const vec4 &_scaleVec);
mat4 rotate(const mat4 &_mat4, const vec4 &_rotateVec);
mat4 rotate(const vec4 &_rotateVec);
mat4 orthographic(float64 _left, float64 _right, float64 _bottom, float64 _top, float64 _near, float64 _far);
mat4 perspective(float64 _fov, float64 _aspect, float64 _near, float64 _far);
mat4 perspective(float64 _fov, float64 _near, float64 _far);
mat4 lookAt(vec3 _position, vec3 _target, vec3 _upVector);
