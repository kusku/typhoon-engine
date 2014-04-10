/*
* Vector4_float.inl
*
* Author: Marc Cuscullola 
* Date: 01/04/14
*/
#include "Vector4_float.h"
#include <assert.h>

//////////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////////
inline Math::Vector4_float::Vector4_float()
: vector(_mm_setzero_ps())
{

}

//////////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////////
inline Math::Vector4_float::Vector4_float(const Vector4_float& other)
{
	(*this) = other;
}

//////////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////////
inline Math::Vector4_float::Vector4_float(const float tx, const float ty, const float tz, const float tw)
{
#ifdef _M_IX86_FP
	float r[4] = { tx, ty, tz, tw };
	vector = _mm_load_ps(r);
#else
	x = tx;
	y = ty;
	z = tz;
	w = tw;
#endif
}

//////////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////////
inline Math::Vector4_float::Vector4_float(const float scalar)
{
#ifdef _M_IX86_FP
	vector = _mm_set1_ps(scalar);
#else
	x = scalar;
	y = scalar;
	z = scalar;
	w = scalar;
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : increment
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator += (const Vector4_float& other)
{
#ifdef _M_IX86_FP
	vector = _mm_add_ps(vector, other.vector);

	return (*this);
#else
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return (*this);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : decrement
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator -= (const Vector4_float& other)
{
#ifdef _M_IX86_FP
	vector = _mm_sub_ps(vector, other.vector);

	return (*this);
#else
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return (*this);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : vector * scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator *= (const float scalar)
{
#ifdef _M_IX86_FP
	vector = _mm_mul_ps(vector, _mm_set1_ps(scalar));
	return (*this);
#else
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;

	return (*this);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : vector / scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator /= (const float scalar)
{
	assert(scalar != 0);

#ifdef _M_IX86_FP
	vector = _mm_div_ps(vector, _mm_set1_ps(scalar));

	return (*this);
#else
	float inv_scalar = 1.f / scalar;
	x *= inv_scalar;
	y *= inv_scalar;
	z *= inv_scalar;
	w *= inv_scalar;

	return(*this);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : vector + scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator += (const float scalar)
{
#ifdef _M_IX86_FP
	vector = _mm_add_ps(vector, _mm_set1_ps(scalar));

	return  (*this);
#else
	x += scalar;
	y += scalar;
	z += scalar;
	w += scalar;

	return (*this);

#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators update : vector - scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator -= (const float scalar)
{
#ifdef _M_IX86_FP
	vector = _mm_sub_ps(vector, _mm_set1_ps(scalar));

	return (*this);
#else
	x -= scalar;
	y -= scalar;
	z -= scalar;
	w -= scalar;

	return (*this);

#endif
}
