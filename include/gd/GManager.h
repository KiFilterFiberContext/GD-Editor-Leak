#pragma once

#include "CCNode.h"

USING_NS_CC;

class GManager : public CCNode
{
public:
	std::string saveFile_; 
	bool setup_;		
	bool quickSave_;

public:
	virtual ~GManager( void );

	void save( void );
	void saveGMTo( std::string path );
	void saveData( DS_Dictionary* dict, std::string save );

	void loadDataFromFile( std::string file );
	void loadFromCompressedString( std::string save );
	void loadFromString( std::string save );

	std::string getCompressedSaveString( void );
	std::string getSaveString( void );

	virtual bool init( void );

	virtual void setup( void );
	virtual void encodeDataTo( DS_Dictionary* dict );
	virtual void dataLoaded( DS_Dictionary* dict );
	virtual void firstLoad( DS_Dictionary* dict );

};