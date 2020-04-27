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

template<typename T> mat4<T> translate(const mat4<T> &_mat4, const vec4<T> &_transVec);
template<typename T> mat4<T> translate(const vec4<T> &_transVec);
template<typename T> mat4<T> scale(const mat4<T> &_mat4, const vec4<T> &_scaleVec);
template<typename T> mat4<T> scale(const vec4<T> &_scaleVec);
template<typename T> mat4<T> rotate(const mat4<T> &_mat4, const vec4<T> &_rotateVec);
template<typename T> mat4<T> rotate(const vec4<T> &_rotateVec);
template<typename T> mat4<T> orthographic(T _left, T _right, T _bottom, T _top, T _near, T _far);
template<typename T> mat4<T> perspective(T _fov, T _aspect, T _near, T _far);
template<typename T> mat4<T> perspective(T _fov, T _near, T _far);
template<typename T> mat4<T> lookAt(vec3<T> _position, vec3<T> _target, vec3<T> _upVector);
