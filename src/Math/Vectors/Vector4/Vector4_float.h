/*
* Vector4_float.h
* Defines a vector4 of floats
*
* Author: Marc Cuscullola 
* Date: 01/04/14
*/

#pragma once

#include <xmmintrin.h>

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

	//Arithmetic operators update
	inline Vector4_float& operator += (const Vector4_float& other);
	inline Vector4_float& operator -= (const Vector4_float& other);
	inline Vector4_float& operator *= (const float scalar);
	inline Vector4_float& operator /= (const float scalar);
	inline Vector4_float& operator += (const float scalar);
	inline Vector4_float& operator -= (const float scalar);
};

#include "Vector4_float.inl"

}