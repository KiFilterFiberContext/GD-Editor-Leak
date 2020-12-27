#pragma once

#include "GDAPI_Macros.h"

#include "CCProtocols.h"
#include <vector>

NS_CC_BEGIN

class CCDictionary;
class CCArray;

//TODO: Add class members to CCFileUtils for Windows
class CC_DLL CCFileUtils : public TypeInfo
{
public:
	unsigned char _unknown[21 * sizeof(int)];

protected:
	CCFileUtils();

public:
	virtual long getClassTypeInfo();
	virtual ~CCFileUtils();

	static void purgeFileUtils();
	static CCFileUtils *sharedFileUtils();

	std::string getAndroidPath() const;
	void removeAllPaths();
	void setAndroidPath(std::string);

	virtual void purgeCachedEntries();
	virtual unsigned char *getFileData(const char *, const char *, unsigned long *);
	virtual unsigned char *getFileDataFromZip(const char *, const char *, unsigned long *);
	virtual std::string fullPathForFilename(const char *, bool);
	virtual void removeFullPath(const char *);
	virtual void loadFilenameLookupDictionaryFromFile(const char *);
	virtual void setFilenameLookupDictionary(CCDictionary *);
	virtual const char *fullPathFromRelativeFile(const char *, const char *);
	virtual void setSearchResolutionsOrder(const std::vector<std::string> &);
	virtual void addSearchResolutionsOrder(const char *);
	virtual const std::vector<std::string> &getSearchResolutionsOrder();
	virtual void setSearchPaths(const std::vector<std::string> &);
	virtual void addSearchPath(const char *);
	virtual void removeSearchPath(const char *);
	virtual const std::vector<std::string> &getSearchPaths();
	virtual std::string getWritablePath() = 0;
	virtual std::string getWritablePath2();
	virtual bool isFileExist(const std::string &) = 0;
	virtual bool isAbsolutePath(const std::string &);
	virtual void setPopupNotify(bool);
	virtual bool isPopupNotify();

protected:
	virtual bool init();
	virtual std::string getNewFilename(const char *);
	virtual bool shouldUseHD();
	virtual std::string addSuffix(std::string, std::string);
	virtual std::string getPathForFilename(const std::string &, const std::string &, const std::string &);
	virtual std::string getFullPathForDirectoryAndFilename(const std::string &, const std::string &);
	virtual CCDictionary *createCCDictionaryWithContentsOfFile(const std::string &);
	virtual bool writeToFile(CCDictionary *, const std::string &);
	virtual CCArray *createCCArrayWithContentsOfFile(const std::string &);
};

#if defined(GDAPI_WINDOWS)

class CC_DLL CCFileUtilsWin32 : public CCFileUtils
{
private:
	CCFileUtilsWin32();

public:
	virtual ~CCFileUtilsWin32();

	std::string utf8Togbk(const char *);

	virtual void addSearchPath(const char *);
	virtual void removeSearchPath(const char *);
	virtual std::string getWritablePath();
	virtual std::string getWritablePath2();
	virtual bool isFileExist(const std::string &);
	virtual bool isAbsolutePath(const std::string &);
	virtual bool init();

protected:
	virtual std::string getPathForFilename(const std::string &, const std::string &, const std::string &);

public:
	virtual std::string fullPathForFilename(const char *);
};

#else

class CC_DLL CCFileUtilsAndroid : public CCFileUtils
{
private:
	CCFileUtilsAndroid();

public:
	virtual ~CCFileUtilsAndroid();

	unsigned char *getFileDataForAsync(const char *, const char *, unsigned long *);

	virtual unsigned char *getFileData(const char *, const char *, unsigned long *);
	virtual std::string getWritablePath();
	virtual bool isFileExist(const std::string &);
	virtual bool isAbsolutePath(const std::string &);
	virtual bool init();
};

#endif

NS_CC_END