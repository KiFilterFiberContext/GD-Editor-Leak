#pragma once

#include "CCTextInputNode.h"

class TextInputDelegate
{
public:
	virtual bool textChanged( CCTextInputNode* ) = 0;
	virtual void textInputOpened( CCTextInputNode* ) = 0;
	virtual void textInputClosed( CCTextInputNode* ) = 0;
	virtual void textInputShouldOffset( CCTextInputNode*, float ) = 0;
	virtual void textInputReturn( CCTextInputNode* ) = 0;
	virtual bool allowTextInput( CCTextInputNode* ) = 0;
	virtual void enterPressed( CCTextInputNode* ) = 0;
};