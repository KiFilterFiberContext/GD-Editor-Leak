#pragma once

#include "GDAPI_Macros.h"

#include <string>
#include "CCObject.h"

NS_CC_BEGIN

class CC_DLL CCString : public CCObject
{
public:
	std::string _sString;

public:
	CCString();
	CCString(const char *str);
	CCString(const std::string &str);
	virtual ~CCString();

	static CCString *create(const std::string &str);
	static CCString *createWithContentsOfFile(const char *path);
	static CCString *createWithData(unsigned const char *dataBytes, unsigned long dataSize);
	static CCString *createWithFormat(const char *fmt, ...);

	bool boolValue() const;
	int compare(const char *str) const;
	double doubleValue() const;
	float floatValue() const;
	const char *getCString() const;
	bool __cdecl initWithFormat(const char *fmt, ...);
	int intValue() const;
	unsigned int length() const;
	unsigned int uintValue() const;

private:
	bool initWithFormatAndValist(const char *fmt, va_list ap);

public:
	virtual CCObject *copyWithZone(CCZone *pZone);
	virtual bool isEqual(const CCObject *pObject);
	virtual void acceptVisitor(CCDataVisitor &rDataVisitor);
};

#define CCStringMake(str) CCString::create(str)
#define ccs CCStringMake

NS_CC_END