#pragma once

class TriggerEffectDelegate
{
public:
	bool defaultEnterEffect_;

public:
	virtual void toggleGroupTriggered( int, bool, int ) = 0;
	virtual void spawnGroup( void ) = 0;
};