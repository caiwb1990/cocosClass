#ifndef __GAME_DISK_H__
#define __GAME_DISK_H__

#include "cocos2d.h"
USING_NS_CC;

class GameDisk : public Node{
private:
	Sprite *diskSpr;
	float dtAngel;
public:
	virtual bool init();

	CREATE_FUNC(GameDisk);

	virtual void update(float dt);
};

#endif