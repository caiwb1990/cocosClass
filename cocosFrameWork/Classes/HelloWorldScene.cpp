#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

	/**/
    // add "HelloWorld" splash screen"
	auto sprite = Sprite::create("bkq.png");
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
  //  this->addChild(sprite, 0);
	sprite->setTag(1024);

	//scheduleUpdate();
	//schedule(schedule_selector(HelloWorld::updateTest), 1.0f, kRepeatForever,5.0f);
	
	/**/
	//color4b rgbA   LayerColorÄ¬ÈÏÃªµã0,0
	LayerColor* redLayer = LayerColor::create(Color4B(255, 0, 0, 255), visibleSize.width / 2, visibleSize.height / 2);
	redLayer->ignoreAnchorPointForPosition(false);
	redLayer->setPosition(visibleSize / 2);
	redLayer->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(redLayer);
	LayerColor* blueLayer = LayerColor::create(Color4B(0, 0, 255, 255), visibleSize.width / 6, visibleSize.height / 6);
	blueLayer->ignoreAnchorPointForPosition(false);
	blueLayer->setAnchorPoint(Vec2(1, 1));
	redLayer->addChild(blueLayer);

	/*
	DrawNode * rect = DrawNode::create();
	addChild(rect);
	rect->setZOrder(10);
	rect->drawSolidRect(Vec2(100,100),Vec2(300,300),Color4F(1,0,0,1));

	DrawNode * rect2 = DrawNode::create();
	addChild(rect2);
	rect2->drawSolidRect(Vec2(150, 150), Vec2(350, 350), Color4F(0, 1, 0, 1));

	DrawNode * rect3 = DrawNode::create();
	addChild(rect3);
	rect3->drawSolidRect(Vec2(200, 200), Vec2(400, 400), Color4F(0, 0, 1, 1));
	*/


    return true;
}


void HelloWorld::updateTest(float dt)
{
	age++;
	CCLOG("age is %d",age);
	if (age > 24)
	{
		unschedule(schedule_selector(HelloWorld::updateTest));
	}
}


void HelloWorld::update(float dt)
{
	Sprite* sprite = (Sprite*)getChildByTag(1024);

	sprite->setPositionX(sprite->getPositionX() + speedX);
	sprite->setPositionY(sprite->getPositionY() + speedY);

	if (sprite->getPositionX() < 0 + sprite->getContentSize().width * 0.5f
		|| sprite->getPositionX() > (visibleSize.width - sprite->getContentSize().width * 0.5f))
	{
		speedX *= -1;
	}

	if (sprite->getPositionY() < 0 + sprite->getContentSize().height * 0.5f
		|| sprite->getPositionY() > visibleSize.height - sprite->getContentSize().height * 0.5f)
	{
		speedY *= -1;
		//unscheduleUpdate();
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
