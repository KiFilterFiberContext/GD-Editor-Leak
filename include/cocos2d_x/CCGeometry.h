#pragma once

#include "GDAPI_Macros.h"

#include <math.h>

NS_CC_BEGIN

class CCSize;

class CC_DLL CCPoint
{
public:
	float x;
	float y;

public:
	CCPoint();
	CCPoint(float x, float y);
	CCPoint(const CCPoint &other);
	CCPoint(const CCSize &size);

	static CCPoint forAngle(float a);

	CCPoint &operator= (const CCPoint &other);
	CCPoint &operator= (const CCSize &size);
	CCPoint operator+(const CCPoint &right) const;
	CCPoint operator-(const CCPoint &right) const;
	CCPoint operator-() const;
	CCPoint operator*(float a) const;
	CCPoint operator/(float a) const;

	float cross(const CCPoint &other) const;
	float dot(const CCPoint &other) const;
	bool equals(const CCPoint &target) const;
	bool fuzzyEquals(const CCPoint &target, float variance) const;
	float getAngle() const;
	float getAngle(const CCPoint &other) const;
	float getDistance(const CCPoint &other) const;
	float getDistanceSq(const CCPoint &other) const;
	float getLength() const;
	float getLengthSq() const;
	CCPoint getPerp() const;
	CCPoint getRPerp() const;
	CCPoint lerp(const CCPoint &other, float alpha) const;
	CCPoint normalize() const;
	CCPoint project(const CCPoint &other) const;
	CCPoint rotate(const CCPoint &other) const;
	CCPoint rotateByAngle(const CCPoint &pivot, float angle) const;
	void setPoint(float x, float y);
	CCPoint unrotate(const CCPoint &other) const;
};

class CC_DLL CCSize
{
public:
	float width;
	float height;

public:
	CCSize();
	CCSize(float width, float height);
	CCSize(const CCSize &other);
	CCSize(const CCPoint &point);

	CCSize &operator=(const CCSize &other);
	CCSize &operator=(const CCPoint &point);
	CCSize operator+(const CCSize &right) const;
	CCSize operator-(const CCSize &right) const;
	CCSize operator*(float a) const;
	CCSize operator/(float a) const;

	void setSize(float width, float height);
	bool equals(const CCSize &target) const;
};

class CC_DLL CCRect
{
public:
	CCPoint origin;
	CCSize size;

public:
	CCRect();
	CCRect(float x, float y, float width, float height);
	CCRect(const CCRect &other);

	CCRect &operator= (const CCRect &other);

	void setRect(float x, float y, float width, float height);
	float getMinX() const;
	float getMidX() const;
	float getMaxX() const;
	float getMinY() const;
	float getMidY() const;
	float getMaxY() const;
	bool equals(const CCRect &rect) const;
	bool containsPoint(const CCPoint &point) const;
	bool intersectsRect(const CCRect &rect) const;
};

//format: "{x,y}"
//example: "{3.0,2.5}"
CCPoint CC_DLL CCPointFromString(const char *str);
//format: "{w, h}"
//example: "{3.0,2.5}"
CCSize CC_DLL CCSizeFromString(const char *str);
//format: "{{x,y},{w, h}}"
//example: "{{3,2},{4,5}}"
CCRect CC_DLL CCRectFromString(const char *str);

#define CCPointMake(x, y) CCPoint((float)(x), (float)(y))
#define CCSizeMake(width, height) CCSize((float)(width), (float)(height))
#define CCRectMake(x, y, width, height) CCRect((float)(x), (float)(y), (float)(width), (float)(height))

const CCPoint CCPointZero = CCPointMake(0, 0);
const CCSize CCSizeZero = CCSizeMake(0, 0);
const CCRect CCRectZero = CCRectMake(0, 0, 0, 0);

NS_CC_END