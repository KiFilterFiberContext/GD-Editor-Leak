#pragma once

#include "GDAPI_Macros.h"

#ifndef kmScalar
#define kmScalar float
#endif

#ifndef kmBool
#define kmBool unsigned char
#endif

#ifndef kmEnum
#define kmEnum unsigned int
#endif

#ifndef KM_FALSE
#define KM_FALSE 0
#endif

#ifndef KM_TRUE
#define KM_TRUE 1
#endif

#define kmPI 3.141592f
#define kmPIOver180 0.017453f
#define kmPIUnder180 57.295779f
#define kmEpsilon 1.0f/64.0f

#ifdef __cplusplus
extern "C" {
#endif

CC_DLL kmScalar kmSQR(kmScalar s);
CC_DLL kmScalar kmDegreesToRadians(kmScalar degrees);
CC_DLL kmScalar kmRadiansToDegrees(kmScalar radians);

CC_DLL kmScalar kmMin(kmScalar lhs, kmScalar rhs);
CC_DLL kmScalar kmMax(kmScalar lhs, kmScalar rhs);
CC_DLL kmBool kmAlmostEqual(kmScalar lhs, kmScalar rhs);

#ifdef __cplusplus
}
#endif