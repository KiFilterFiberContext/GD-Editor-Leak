#pragma once

#include "GDAPI_Macros.h"

#define KM_PLANE_LEFT 0
#define KM_PLANE_RIGHT 1
#define KM_PLANE_BOTTOM 2
#define KM_PLANE_TOP 3
#define KM_PLANE_NEAR 4
#define KM_PLANE_FAR 5

#include "utility.h"

struct kmVec3;
struct kmVec4;
struct kmMat4;

typedef struct kmPlane
{
	kmScalar a, b, c, d;
} kmPlane;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum POINT_CLASSIFICATION
{
	POINT_INFRONT_OF_PLANE = 0,
	POINT_BEHIND_PLANE,
	POINT_ON_PLANE,
} POINT_CLASSIFICATION;

CC_DLL const kmScalar kmPlaneDot(const kmPlane *pP, const struct kmVec4 *pV);
CC_DLL const kmScalar kmPlaneDotCoord(const kmPlane *pP, const struct kmVec3 *pV);
CC_DLL const kmScalar kmPlaneDotNormal(const kmPlane *pP, const struct kmVec3 *pV);
CC_DLL kmPlane *const kmPlaneFromPointNormal(kmPlane *pOut, const struct kmVec3 *pPoint, const struct kmVec3 *pNormal);
CC_DLL kmPlane *const kmPlaneFromPoints(kmPlane *pOut, const struct kmVec3 *p1, const struct kmVec3 *p2, const struct kmVec3 *p3);
CC_DLL kmVec3  *const kmPlaneIntersectLine(struct kmVec3 *pOut, const kmPlane *pP, const struct kmVec3 *pV1, const struct kmVec3 *pV2);
CC_DLL kmPlane *const kmPlaneNormalize(kmPlane *pOut, const kmPlane *pP);
CC_DLL kmPlane *const kmPlaneScale(kmPlane *pOut, const kmPlane *pP, kmScalar s);
CC_DLL const POINT_CLASSIFICATION kmPlaneClassifyPoint(const kmPlane *pIn, const kmVec3 *pP);

#ifdef __cplusplus
}
#endif