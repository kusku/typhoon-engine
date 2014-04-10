/*
* Vector4_float.h
* Defines a vector4 of floats
*
* Author: Marc Cuscullola
* Date: 01/04/14
*/

#pragma once

#include <xmmintrin.h>
#include <emmintrin.h>

namespace Math
{

class Vector4_float
{
public:
#ifdef _M_IX86_FP
    __m128 vector;
#else
    float x, y, z, w;
#endif

public:
    // Constructors
    inline Vector4_float();
    inline Vector4_float(const Vector4_float& other);
    inline Vector4_float(const float tx, const float ty, const float tz, const float tw);
    inline Vector4_float(const float scalar);
#ifdef _M_IX86_FP
    inline Vector4_float(const __m128& other);
#endif

    // Arithmetic operators
    inline        Vector4_float  operator + (const Vector4_float& other) const;
    inline        Vector4_float  operator - (const Vector4_float& other) const;
    inline        Vector4_float  operator * (const float scalar) const;
    inline        Vector4_float  operator / (const float scalar) const;
    inline        Vector4_float  operator + (const float scalar) const;
    inline        Vector4_float  operator - (const float scalar) const;
    inline        Vector4_float  operator - () const;
    inline        Vector4_float& operator + ();
    inline const  Vector4_float& operator + () const;


    // Arithmetic operators update
    inline Vector4_float& operator += (const Vector4_float& other);
    inline Vector4_float& operator -= (const Vector4_float& other);
    inline Vector4_float& operator *= (const float scalar);
    inline Vector4_float& operator /= (const float scalar);
    inline Vector4_float& operator += (const float scalar);
    inline Vector4_float& operator -= (const float scalar);

    // Assign operators
    inline Vector4_float& operator () (const float tx, const float ty, const float tz, const float tw);
    inline void Set(const float tx, const float ty, const float tz, const float tw);
    inline void Zero();

};

#include "Vector4_float.inl"

}