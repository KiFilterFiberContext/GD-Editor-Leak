#pragma once

#include "GDAPI_Macros.h"

#include "CCGeometry.h"
#include "CCObject.h"
#include "CCArray.h"
#include "CCDictionary.h"
#include "support/pugixml.hpp"

#include <string>
#include <vector>
#include <map>

class CC_DLL DS_Dictionary
{
public:
	pugi::xml_document _doc;
	std::vector<pugi::xml_node> _nodes;
	bool _compatibility;

public:
	DS_Dictionary();
	~DS_Dictionary();

	static void copyFile(const char *file1, const char *file2);

	void addBoolValuesToMapForKey(std::map<std::string, bool> &, const char *, bool);
	void addBoolValuesToMapForKeySpecial(std::map<std::string, bool> &, const char *, bool);
	void checkCompatibility();
	cocos2d::CCObject *decodeObjectForKey(const char *key, bool, int);
	std::vector<std::string> getAllKeys();
	cocos2d::CCArray *getArrayForKey(const char *key, bool);
	bool getBoolForKey(const char *key);
	cocos2d::CCDictionary *getDictForKey(const char *key, bool);
	float getFloatForKey(const char *key);
	unsigned int getIndexOfKey(const char *key);
	unsigned int getIndexOfKeyWithClosestAlphaNumericalMatch(const char *key);
	int getIntegerForKey(const char *key);
	std::string getKey(unsigned int index);
	unsigned int getNumKeys();
	cocos2d::CCObject *getObjectForKey(const char *key);
	std::vector<cocos2d::CCRect> getRectArrayForKey(const char *key);
	cocos2d::CCRect getRectForKey(const char *key);
	std::vector<std::string> getStringArrayForKey(const char *key);
	std::string getStringForKey(const char *key);
	std::vector<cocos2d::CCPoint> getVec2ArrayForKey(const char *key);
	cocos2d::CCPoint getVec2ForKey(const char *key);
	bool loadRootSubDictFromCompressedFile(const char *file);
	bool loadRootSubDictFromFile(const char *file);
	bool loadRootSubDictFromString(std::string str);
	void removeAllKeys();
	void removeKey(unsigned int key);
	void removeKey(const char *key);
	bool saveRootSubDictToCompressedFile(const char *file);
	bool saveRootSubDictToFile(const char *file);
	std::string saveRootSubDictToString();
	void setArrayForKey(const char *key, cocos2d::CCArray *pArray);
	void setBoolForKey(const char *key, bool, bool);
	void setBoolForKey(const char *key, bool);
	void setBoolMapForKey(const char *key, std::map<std::string, bool> &);
	void setDictForKey(const char *key, cocos2d::CCDictionary *pDict);
	void setFloatForKey(const char *key, float val);
	void setFloatForKey(const char *key, float val, bool);
	void setIntegerForKey(const char *key, int);
	void setIntegerForKey(const char *key, int, bool);
	void setObjectForKey(const char *key, cocos2d::CCObject *);
	void setRectArrayForKey(const char *key, const std::vector<cocos2d::CCRect> &);
	void setRectArrayForKey(const char *key, const std::vector<cocos2d::CCRect> &, bool);
	void setRectForKey(const char *key, const cocos2d::CCRect &);
	void setRectForKey(const char *key, const cocos2d::CCRect &, bool);
	void setStringArrayForKey(const char *key, const std::vector<std::string> &);
	void setStringArrayForKey(const char *key, const std::vector<std::string> &, bool);
	void setStringForKey(const char *key, const std::string &str);
	void setStringForKey(const char *key, const std::string &str, bool);
	void setSubDictForKey(const char *key);
	void setSubDictForKey(const char *key, bool, bool);
	void setVec2ArrayForKey(const char *key, const std::vector<cocos2d::CCPoint> &vecs);
	void setVec2ArrayForKey(const char *key, const std::vector<cocos2d::CCPoint> &vecs, bool);
	void setVec2ForKey(const char *key, const cocos2d::CCPoint &vec);
	void setVec2ForKey(const char *key, const cocos2d::CCPoint &vec, bool);
	void stepBackToRootSubDict();
	bool stepIntoSubDictWithKey(const char *key);
	void stepOutOfSubDict();

private:
	std::string cleanStringWhiteSpace(const std::string &);
	bool rectFromString(const std::string &, cocos2d::CCRect &);
	void split(const std::string &, const char *, std::vector<std::string> &);
	bool splitWithForm(const std::string &, std::vector<std::string> &);
	bool vec2FromString(const std::string &, cocos2d::CCPoint &);
};