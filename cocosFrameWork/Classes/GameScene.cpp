#include "Common/common.h"
#include "GameScene.h"
#include "GameDisk.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//init
	auto gameLayer = Layer::create();
	this->addChild(gameLayer);
	//end

	//root node
	auto rootNood = GameDisk::create();
	gameLayer->addChild(rootNood);
	
	
	//end

	return true;
}