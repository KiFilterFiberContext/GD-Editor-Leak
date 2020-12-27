#pragma once

#include "GDAPI_Macros.h"

#include "support/ccTypes.h"
#include "CCTexture2D.h"

NS_CC_BEGIN

class CC_DLL TypeInfo
{
public:
	virtual long getClassTypeInfo() = 0;
};

class CC_DLL CCRGBAProtocol
{
public:
	virtual void setColor(const ccColor3B &color) = 0;
	virtual const ccColor3B &getColor() = 0;
	virtual const ccColor3B &getDisplayedColor() = 0;
	virtual GLubyte getDisplayedOpacity() = 0;
	virtual GLubyte getOpacity() = 0;
	virtual void setOpacity(GLubyte opacity) = 0;
	virtual void setOpacityModifyRGB(bool bValue) = 0;
	virtual bool isOpacityModifyRGB() = 0;
	virtual bool isCascadeColorEnabled() = 0;
	virtual void setCascadeColorEnabled(bool bValue) = 0;
	virtual void updateDisplayedColor(const ccColor3B &color) = 0;
	virtual bool isCascadeOpacityEnabled() = 0;
	virtual void setCascadeOpacityEnabled(bool bValue) = 0;
	virtual void updateDisplayedOpacity(GLubyte opacity) = 0;
};

class CC_DLL CCBlendProtocol
{
public:
	virtual void setBlendFunc(ccBlendFunc blendFunc) = 0;
	virtual ccBlendFunc getBlendFunc() = 0;
};

class CC_DLL CCTextureProtocol : public CCBlendProtocol
{
public:
	virtual CCTexture2D *getTexture() = 0;
	virtual void setTexture(CCTexture2D *pTexture) = 0;
};

class CC_DLL CCLabelProtocol
{
public:
	virtual void setString(const char *label) = 0;
	virtual const char *getString() = 0;
};

class CC_DLL CCDirectorDelegate
{
public:
	virtual void updateProjection() = 0;
};

NS_CC_END