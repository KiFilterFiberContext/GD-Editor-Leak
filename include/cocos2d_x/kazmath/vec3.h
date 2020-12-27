#pragma once

#include "GDAPI_Macros.h"

#ifndef kmScalar
#define kmScalar float
#endif

struct kmMat4;

typedef struct kmVec3
{
	kmScalar x;
	kmScalar y;
	kmScalar z;
} kmVec3;

#ifdef __cplusplus
extern "C" {
#endif

CC_DLL kmVec3 *kmVec3Fill(kmVec3 *pOut, kmScalar x, kmScalar y, kmScalar z);
CC_DLL kmScalar kmVec3Length(const kmVec3 *pIn);
CC_DLL kmScalar kmVec3LengthSq(const kmVec3 *pIn);
CC_DLL kmVec3 *kmVec3Normalize(kmVec3 *pOut, const kmVec3 *pIn);
CC_DLL kmVec3 *kmVec3Cross(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
CC_DLL kmScalar kmVec3Dot(const kmVec3 *pV1, const kmVec3 *pV2);
CC_DLL kmVec3 *kmVec3Add(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
CC_DLL kmVec3 *kmVec3Subtract(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
CC_DLL kmVec3 *kmVec3Transform(kmVec3 *pOut, const kmVec3 *pV1, const struct kmMat4 *pM);
CC_DLL kmVec3 *kmVec3TransformNormal(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
CC_DLL kmVec3 *kmVec3TransformCoord(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
CC_DLL kmVec3 *kmVec3Scale(kmVec3 *pOut, const kmVec3 *pIn, const kmScalar s);
CC_DLL int kmVec3AreEqual(const kmVec3 *p1, const kmVec3 *p2);
CC_DLL kmVec3 *kmVec3InverseTransform(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
CC_DLL kmVec3 *kmVec3InverseTransformNormal(kmVec3 *pOut, const kmVec3 *pVect, const struct kmMat4 *pM);
CC_DLL kmVec3 *kmVec3Assign(kmVec3 *pOut, const kmVec3 *pIn);
CC_DLL kmVec3 *kmVec3Zero(kmVec3 *pOut);

#ifdef __cplusplus
}
#endif