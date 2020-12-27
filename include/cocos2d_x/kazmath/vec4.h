#pragma once

#include "GDAPI_Macros.h"

#include "utility.h"

struct kmMat4;

#pragma pack(push, 1)
typedef struct kmVec4
{
	kmScalar x;
	kmScalar y;
	kmScalar z;
	kmScalar w;
} kmVec4;
#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif

CC_DLL kmVec4 *kmVec4Fill(kmVec4 *pOut, kmScalar x, kmScalar y, kmScalar z, kmScalar w);
CC_DLL kmVec4 *kmVec4Add(kmVec4 *pOut, const kmVec4 *pV1, const kmVec4 *pV2);
CC_DLL kmScalar kmVec4Dot(const kmVec4 *pV1, const kmVec4 *pV2);
CC_DLL kmScalar kmVec4Length(const kmVec4 *pIn);
CC_DLL kmScalar kmVec4LengthSq(const kmVec4 *pIn);
CC_DLL kmVec4 *kmVec4Lerp(kmVec4 *pOut, const kmVec4 *pV1, const kmVec4 *pV2, kmScalar t);
CC_DLL kmVec4 *kmVec4Normalize(kmVec4 *pOut, const kmVec4 *pIn);
CC_DLL kmVec4 *kmVec4Scale(kmVec4 *pOut, const kmVec4 *pIn, const kmScalar s);
CC_DLL kmVec4 *kmVec4Subtract(kmVec4 *pOut, const kmVec4 *pV1, const kmVec4 *pV2);
CC_DLL kmVec4 *kmVec4Transform(kmVec4 *pOut, const kmVec4 *pV, const struct kmMat4 *pM);
CC_DLL kmVec4 *kmVec4TransformArray(kmVec4 *pOut, unsigned int outStride, const kmVec4 *pV, unsigned int vStride, const struct kmMat4 *pM, unsigned int count);
CC_DLL int     kmVec4AreEqual(const kmVec4 *p1, const kmVec4 *p2);
CC_DLL kmVec4 *kmVec4Assign(kmVec4 *pOut, const kmVec4 *pIn);

#ifdef __cplusplus
}
#endif