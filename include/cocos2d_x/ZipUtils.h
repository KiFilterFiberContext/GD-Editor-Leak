#pragma once

#include "GDAPI_Macros.h"

#include <string>

NS_CC_BEGIN

class CC_DLL ZipUtils
{
private:
	static bool s_bEncryptionKeyIsValid;
	static unsigned int *s_uEncryptedPvrKeyParts;
	static unsigned int *s_uEncryptionKey;

public:
	static std::string base64DecodeEnc(std::string str, std::string key);
	static std::string base64EncodeEnc(std::string str, std::string key);
	static std::string base64URLDecode(std::string str);
	static std::string base64URLEncode(std::string str);
	static int ccDeflateMemory(unsigned char *, unsigned int, unsigned char **);
	static int ccInflateCCZFile(const char *, unsigned char **);
	static int ccInflateGZipFile(const char *, unsigned char **);
	static int ccInflateMemory(unsigned char *, unsigned int, unsigned char **);
	static int ccInflateMemoryWithHint(unsigned char *, unsigned int, unsigned char **, unsigned int);
	static void ccSetPvrEncryptionKey(unsigned int, unsigned int, unsigned int, unsigned int);
	static void ccSetPvrEncryptionKeyPart(int, unsigned int);
	static std::string compressString(std::string str, bool, int);
	static std::string decompressString(std::string str, bool, int);
	static std::string decompressString2(unsigned char *, bool, int, int);
	static std::string encryptDecrypt(std::string str, int);
	static std::string encryptDecryptWKey(std::string str, std::string key);
	static unsigned char hexToChar(const std::string &hexstr);
	static std::string urlDecode(const std::string &str);

private:
	static unsigned int ccChecksumPvr(unsigned int const *, int);
	static void ccDecodeEncodedPvr(unsigned int *, int);
	static int ccInflateMemoryWithHint(unsigned char *, unsigned int, unsigned char **, unsigned int *, unsigned int);
};

NS_CC_END