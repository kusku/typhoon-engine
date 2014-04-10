/*
* Vector4_float.inl
*
* Author: Marc Cuscullola 
* Date: 01/04/14
*/
#include "Vector4_float.h"
#include <assert.h>

#ifdef _M_IX86_FP
static const __m128 SIGNMASK = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));
#endif

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
// Constructor
//////////////////////////////////////////////////////////////////////////
#ifdef _M_IX86_FP
inline Math::Vector4_float::Vector4_float(const __m128& other)
{
    vector = other;
}
#endif

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : add two vectors
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator + (const Vector4_float& other) const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_add_ps(vector, other.vector) );
#else
    return (Vector4_float(x + other.x,
        y + other.y,
        z + other.z,
        w + other.w));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : substract two vectors
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator - (const Vector4_float& other) const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_sub_ps(vector, other.vector) );
#else
    return (Vector4_float(x - other.x,
        y - other.y,
        z - other.z,
        w - other.w));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : multiply two vectors
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator * (const float scalar) const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_mul_ps(vector, _mm_set1_ps(scalar)) );
#else
    return (Vector4_float(x * scalar,
        y * scalar,
        z * scalar,
        w * scalar));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : divide two vectors
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator / (const float scalar) const
{
    assert(scalar != 0);
    float inv_scalar = 1.f / scalar;

#ifdef _M_IX86_FP
    return Vector4_float( _mm_mul_ps(vector, _mm_set1_ps(inv_scalar)) );
#else
    return (Vector4_float(x * inv_scalar,
        y * inv_scalar,
        z * inv_scalar,
        w * inv_scalar));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : add vector with scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator + (const float scalar) const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_add_ps(vector, _mm_set1_ps(scalar)) );
#else
    return (Vector4_float(x + scalar,
        y + scalar,
        z + scalar,
        w + scalar));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : substract vectow with scalar
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator - (const float scalar) const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_sub_ps(vector, _mm_set1_ps(scalar)) );
#else
    return (Vector4_float(x - scalar,
        y - scalar,
        z - scalar,
        w - scalar));
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : Change the sign
//////////////////////////////////////////////////////////////////////////
inline Vector4_float  Math::Vector4_float::operator - () const
{
#ifdef _M_IX86_FP
    return Vector4_float( _mm_xor_ps(vector, SIGNMASK) );
#else
    return Vector4_float(-x, -y, -z, -w);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : positive sign
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator + ()
{
    return (*this);
}

//////////////////////////////////////////////////////////////////////////
//Arithmetic operators : const positive sign
//////////////////////////////////////////////////////////////////////////
inline const  Vector4_float& Math::Vector4_float::operator + () const
{
    return (*this);
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
    float inv_scalar = 1.f / scalar;

#ifdef _M_IX86_FP
	vector = _mm_mul_ps(vector, _mm_set1_ps(inv_scalar));

	return (*this);
#else
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

//////////////////////////////////////////////////////////////////////////
//Assign operators : set values
//////////////////////////////////////////////////////////////////////////
inline Vector4_float& Math::Vector4_float::operator () (const float tx, const float ty, const float tz, const float tw)
{
#ifdef _M_IX86_FP
    float r[4] = { tx, ty, tz, tw };
    vector = _mm_load_ps(r);

    return (*this);
#else
    x = tx;
    y = ty;
    z = tz;
    w = tw;

    return (*this);
#endif
}

//////////////////////////////////////////////////////////////////////////
//Assign operators : set values
//////////////////////////////////////////////////////////////////////////
inline void Math::Vector4_float::Set(const float tx, const float ty, const float tz, const float tw)
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
//Assign operators : zero
//////////////////////////////////////////////////////////////////////////
inline void Math::Vector4_float::Zero()
{
#ifdef _M_IX86_FP
    vector = _mm_setzero_ps();
#else
    x = 0.f;
    y = 0.f;
    z = 0.f;
    w = 0.f;
#endif
}
