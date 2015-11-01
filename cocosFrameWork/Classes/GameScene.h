#ifndef __GAME_SCENE_H__  //防止重复引用包含
#define  __GAME_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public Scene{

public:
virtual bool init();


CREATE_FUNC(GameScene);
};
#endif // !__GAME_SCENE_H__
