#pragma once

class UploadActionDelegate
{
public:
	virtual void uploadActionFinished( int, int ) = 0;
	virtual void uploadActionFailed( int, int ) = 0;
};