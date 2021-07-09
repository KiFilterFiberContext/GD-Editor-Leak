#pragma once

#include "CCLayer.h"

USING_NS_CC;

enum GJHttpType
{
	kUploadLevel = 1,
	kGetOnlineLevels,
	kGetMapPacks,
	kDownloadLevel,
	kUpdateLevel,
	kRateStars,
	kDeleteServerLevel,
	kSetLevelStars,
	kSetLevelFeatured,
	kUpdateUserScore,
	kGetLeaderboardScores,
	kGetLevelComments,
	kUploadComment,
	kDeleteComment,
	kLikeItem,
	kRestoreItems,
	kSubmitUserInfo,
	kReportLevel,
	kGetSongInfo,
	kBackupAccount,
	kSyncAccount,
	kRegisterAccount,
	kLoginAccount,
	kUpdateDescription,
	kGetAccountComments,
	kUpdateAccountSettings,
	kGetGJUserInfo,
	kGetFriendRequests,
	kUploadFriendRequest,
	kDeleteFriendRequest,
	kAcceptFriendRequest,
	kReadFriendRequest,
	kRemoveFriend,
	kBlockUser,
	kUnblockUser,
	kGetUserList,
	kGetUserMessages,
	kDownloadUserMessage,
	kDeleteUserMessages,
	kUploadUserMessage,
	kGetUsers,
	kBanUser,
	kRequestUserAccess,
	kGetLevelSaveData,
	kSuggestLevelStars,
	kGetGJRewards,
	kGetGJChallenges,
	kGetGJDailyLevelState,
	kUnknown49,
	kRateDemon,
	kGetLevelLeaderboard,
	kGetGauntlets,
	kGetTopArtists,
	kGetAccountBackupURL,
	kGetAccountSyncURL,
	kUnknown56,
	kJoinMPLobby, 
	kExitMPLobby
};

class GameLevelManager : public CCNode
{
public:
	CCDictionary* mainLevels_; // 0xF8
	CCDictionary* valueDict_; // 0xFC
	// ...

public:
	virtual ~GameLevelManager( );

	static GameLevelManager* sharedState( );

	void ProcessHttpRequest( std::string url, std::string requestData, std::string dlKey, GJHttpType type );

	virtual bool init( );
};
