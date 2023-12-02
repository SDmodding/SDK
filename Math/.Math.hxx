#pragma once
#define UFG_MIN(a,b) (((a) < (b)) ? (a) : (b))
#define UFG_MAX(a,b) (((a) > (b)) ? (a) : (b))

#define UFG_PI					3.1415926535897932384626433832795f

#define UFG_Deg2Rad_Mul			(UFG_PI / 180.f)
#define UFG_Deg2Rad(x)			(x * UFG_Deg2Rad_Mul)

#define UFG_Rad2Deg_Mul			(180.f / UFG_PI)
#define UFG_Rad2Deg(x)			(x * UFG_Rad2Deg_Mul)

// Includes
#include "HalfFloat.hxx"
#include "Vector2.hxx"
#include "Vector3.hxx"
#include "Vector4.hxx"
#include "Matrix44.hxx"
#include "Quaternion.hxx"