#pragma once

#include "CCNode.h"
#include "GJGameLevel.h"
#include "GJEffectManager.h"


class LevelSettingsObject : public cocos2d::CCNode
{
public:
  uint8_t _pad[0x0C];
  GJEffectManager *effectManager; // 0xF4
  int startMode_;
  int startSpeed_;
  bool startMiniMode_;
  bool startDualMode_;
  bool twoPlayerMode_;
  bool platformerMode_; // 0x107
  float songOffset;
  bool fadeIn_;
  bool fadeOut_;
  bool gap10E[2];
  int BGIdx_;
  int GIdx_;
  int fontIdx_;
  bool isLimited_;
  bool gravityFlipped_;
  bool byte11E;
  bool byte11F;
  int dword120;
  GJGameLevel *gameLevel;
  std::string songString_;
  bool byte12C;
  bool gap12D[3];
  int lastColorPage_;
  int GLineIdx_;
  bool byte138;
  bool isVisible_;

public:
    LevelSettingsObject();
    virtual ~LevelSettingsObject();

    static LevelSettingsObject* create( );
};