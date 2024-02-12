#pragma once
#define UFG_MIN(a,b) (((a) < (b)) ? (a) : (b))
#define UFG_MAX(a,b) (((a) > (b)) ? (a) : (b))

#define UFG_PI					3.1415926535897932384626433832795f

#define UFG_Deg2Rad_Mul			(UFG_PI / 180.f)
#define UFG_Deg2Rad(x)			(x * UFG_Deg2Rad_Mul)

#define UFG_Rad2Deg_Mul			(180.f / UFG_PI)
#define UFG_Rad2Deg(x)			(x * UFG_Rad2Deg_Mul)

// Includes
#include "HalfFloat.hh"
#include "Vector2.hh"
#include "Vector3.hh"
#include "Vector4.hh"
#include "Matrix44.hh"
#include "Quaternion.hh"