#include "Common/common.h"
#include "GameDisk.h"

bool GameDisk::init()
{
	if (! Node::init())
	{
		return false;
	}
	//init
	auto bgSpr = Sprite::create("bg.png");
	this->addChild(bgSpr);

	diskSpr = Sprite::create("disk.png");
	this->addChild(diskSpr);

	this->setPosition(DISPLAY_CX, DISPLAY_CY);

	auto buttonNode = Node::create();
	this->addChild(buttonNode);

	auto beginBtn = Sprite::create("arrow_begin.png");
	beginBtn->setPositionY(35);
	buttonNode->addChild(beginBtn);

	auto endBtn = Sprite::create("arrow_end.png");
	endBtn->setPositionY(35);
	buttonNode->addChild(endBtn);

	scheduleUpdate();
	dtAngel = 5.9f;

	return true;
}

void GameDisk::update(float dt)
{
	diskSpr->setRotation(diskSpr->getRotation() + dtAngel);

	dtAngel *= 0.99f;

	if (dtAngel <= 0.3f)
	{
		unscheduleUpdate();
		CCLOG("end");
	}

}