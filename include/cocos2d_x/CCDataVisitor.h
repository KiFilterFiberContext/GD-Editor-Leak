#pragma once

#include "GDAPI_Macros.h"

#include <string>

class CCObject;
class CCBool;
class CCInteger;
class CCFloat;
class CCDouble;
class CCString;
class CCArray;
class CCDictionary;
class CCSet;

NS_CC_BEGIN

class CC_DLL CCDataVisitor
{
public:
	CCDataVisitor();
	virtual ~CCDataVisitor();

	virtual void visitObject(const CCObject *p) = 0;

	virtual void visit(const CCBool *p);
	virtual void visit(const CCInteger *p);
	virtual void visit(const CCFloat *p);
	virtual void visit(const CCDouble *p);
	virtual void visit(const CCString *p);
	virtual void visit(const CCArray *p);
	virtual void visit(const CCDictionary *p);
	virtual void visit(const CCSet *p);
};

class CC_DLL CCPrettyPrinter : public CCDataVisitor
{
public:
	int _indentLevel;
	std::string _indentStr;
	std::string _result;

public:
	CCPrettyPrinter(int indentLevel = 0);
	virtual ~CCPrettyPrinter();

private:
	void setIndentLevel(int indentLevel);

public:
	virtual void visitObject(const CCObject *p);
	virtual void visit(const CCBool *p);
	virtual void visit(const CCInteger *p);
	virtual void visit(const CCFloat *p);
	virtual void visit(const CCDouble *p);
	virtual void visit(const CCString *p);
	virtual void visit(const CCArray *p);
	virtual void visit(const CCDictionary *p);
	virtual void visit(const CCSet *p);

	virtual void clear();
	virtual std::string getResult();
};

NS_CC_END