#pragma once


typedef void *_HWND;
typedef void *_HGLRC;
typedef void *_HMODULE;
typedef void *_HANDLE;
typedef void *_PVOID;

// TODO(BODYA): Add all members to classes
// TODO(BODYA): Add all arguments names to classes functions
// TODO(BODYA): Add comment for each function

#define CC_DLL
#define GD_DLL			__attribute__((visibility("default")))
// #define GD_DLL


#define NS_CC_BEGIN			namespace cocos2d {
#define NS_CC_END				}
#define USING_NS_CC			using namespace cocos2d
#define NS_CC_EXT_BEGIN		namespace cocos2d { namespace extension {
#define NS_CC_EXT_END		} }
#define USING_NS_CC_EXT		using namespace cocos2d::extension

#define CC_SAFE_DELETE(p)				do { if(p) { delete (p); (p) = 0; } } while(0)
#define CC_SAFE_DELETE_ARRAY(p)	do { if(p) { delete[] (p); (p) = 0; } } while(0)
#define CC_SAFE_FREE(p)					do { if(p) { free(p); (p) = 0; } } while(0)
#define CC_SAFE_RELEASE(p)				do { if(p) { (p)->release(); } } while(0)
#define CC_SAFE_RELEASE_NULL(p)	do { if(p) { (p)->release(); (p) = 0; } } while(0)
#define CC_SAFE_RETAIN(p)				do { if(p) { (p)->retain(); } } while(0)
#define CC_BREAK_IF(cond)				if(cond) break

#define CC_UNUSED_PARAM(unusedparam)		(void)unusedparam

#if defined(GDAPI_WINDOWS)
#define CC_DEPRECATED_ATTRIBUTE			__declspec(deprecated) 
#else
#define CC_DEPRECATED_ATTRIBUTE			__attribute__((deprecated))
#endif 

#define CC_PROPERTY_READONLY(varType, varName, funName) \
	protected: varType varName; \
	public: virtual varType get##funName();

#define CC_PROPERTY_READONLY_PASS_BY_REF(varType, varName, funName) \
	protected: varType varName; \
	public: virtual const varType &get##funName();

#define CC_PROPERTY(varType, varName, funName) \
	protected: varType varName; \
	public: virtual varType get##funName(); \
	public: virtual void set##funName(varType var);

#define CC_PROPERTY_PASS_BY_REF(varType, varName, funName) \
	protected: varType varName; \
	public: virtual const varType &get##funName(); \
	public: virtual void set##funName(const varType &var);

#define CC_SYNTHESIZE_READONLY(varType, varName, funName) \
	protected: varType varName; \
	public: virtual varType get##funName() const { return varName; }

#define CC_SYNTHESIZE_READONLY_PASS_BY_REF(varType, varName, funName) \
	protected: varType varName;  \
	public: virtual const varType &get##funName() const { return varName; }

#define CC_SYNTHESIZE(varType, varName, funName) \
	protected: varType varName; \
	public: virtual varType get##funName() const { return varName; } \
	public: virtual void set##funName(varType var) { varName = var; }

#define CC_SYNTHESIZE_PASS_BY_REF(varType, varName, funName) \
	protected: varType varName; \
	public: virtual const varType &get##funName() const { return varName; } \
	public: virtual void set##funName(const varType &var) { varName = var; }

#define CC_SYNTHESIZE_RETAIN(varType, varName, funName) \
	private: varType varName; \
	public: virtual varType get##funName() const { return varName; } \
	public: virtual void set##funName(varType var) { \
	    if (varName != var) { \
	        CC_SAFE_RETAIN(var); \
	        CC_SAFE_RELEASE(varName); \
	        varName = var; \
	    } \
	}

#define CC_SWAP(x, y, type) { type temp = x; x = y; y = temp; }
#define CCRANDOM_MINUS1_1() ((2.0f * ((float)rand() / RAND_MAX)) - 1.0f)
#define CCRANDOM_0_1() ((float)rand() / RAND_MAX)
#define CC_DEGREES_TO_RADIANS(__ANGLE__) ((__ANGLE__) * 0.01745329252f)
#define CC_RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) * 57.29577951f)
#define kCCRepeatForever (UINT_MAX - 1)
#define CC_HOST_IS_BIG_ENDIAN (bool)(*(unsigned short *)"\0\xff" < 0x100) 
#define CC_SWAP32(i) ((i & 0x000000ff) << 24 | (i & 0x0000ff00) << 8 | (i & 0x00ff0000) >> 8 | (i & 0xff000000) >> 24)
#define CC_SWAP16(i) ((i & 0x00ff) << 8 | (i & 0xff00) >> 8)   
#define CC_SWAP_INT32_LITTLE_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true) ? CC_SWAP32(i) : (i))
#define CC_SWAP_INT16_LITTLE_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true) ? CC_SWAP16(i) : (i))
#define CC_SWAP_INT32_BIG_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true) ? (i) : CC_SWAP32(i))
#define CC_SWAP_INT16_BIG_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true) ? (i) : CC_SWAP16(i))


#define GDAPI_ASM
#define GDAPI_INLINE
#define GDAPI_NOINLINE
#define GD_NAKED

#define GDAPI_SOURCE		/* The function source code is placed in the library */
#define GDAPI_CUSTOM		/* The function source code is placed in the library */

//GeometryDash handle
extern GD_DLL _HMODULE staticGDDll;
//GeometryDash version string
extern GD_DLL const char *staticGDVersion;
//GeometryDash version double
extern GD_DLL double staticGDVersionD;

#define DECLARE_GD_NS(className)					namespace
#define DECLARE_GD_FUNC(funcName)
#define GET_GD_FUNC(className, funcName)

#define JMP_GD_FUNC(className, funcName)
#define CALL_GD_FUNC(className, funcName)
#define BODY_GD_FUNC(className, funcName)
#define MAKE_GD_FUNC(returnType, className, funcName, ...)
#define MAKE_GD_FUNC_CTOR(className, ...)
#define MAKE_GD_FUNC_DTOR(className)
