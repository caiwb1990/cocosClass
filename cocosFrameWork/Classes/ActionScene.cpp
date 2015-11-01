#include "Common/common.h"

#include "ActionScene.h"

bool ActionScene::init()
{
	if (! Scene::init())
	{
		return false;
	}

	//
	auto bkqSpr = Sprite::create("bkq1.png");
	bkqSpr->setPosition(DISPLAY_CX, DISPLAY_CY);
	bkqSpr->setTag(111);
	bkqSpr->setName("bkq");
	addChild(bkqSpr);

	frmTime = 0; 
	//scheduleUpdate();

	//to by
	//auto action = MoveBy::create(2.0f, Vec2(200, 0));
	//auto action = MoveTo::create(2.0f, Vec2(200, 0));
	
	//auto action = JumpTo::create(2.0f, Vec2(DISPLAY_CX + 200, DISPLAY_CY), 100, 5);
	//auto action = JumpBy::create(0.5f, Vec2(200, 0), 200, 1);

	//±´Èû¶ûÇúÏß
	/*ccBezierConfig bezierCfg;
	bezierCfg.endPosition = Point(DISPLAY_CX + 400, DISPLAY_CY);
	bezierCfg.controlPoint_1 = Point(DISPLAY_CX , DISPLAY_CY +200);
	bezierCfg.controlPoint_2 = Point(DISPLAY_CX + 500, DISPLAY_CY - 200);
	auto action = CCBezierTo::create(2.0f,bezierCfg);
	*/

	//auto actionScale = ScaleTo::create(2.0f,0.5);
	//auto actionRotate = RotateBy::create(2.0f, 180);

	//auto action = Sequence::create(actionScale,actionRotate,NULL);
	//auto action = Spawn::create(actionScale, actionRotate, NULL);

	/**/
	auto moveActionRight = MoveBy::create(1.0f, Vec2(200, 0));
	auto moveActionLeft = moveActionRight->reverse();//MoveBy::create(1.0f, Vec2(-200, 0));

	auto flipAction = FlipX::create(true);
	auto flipAction1 = FlipX::create(false);
	auto delayAction = DelayTime::create(1.0f);

	auto seqAction = Sequence::create(moveActionRight, delayAction,flipAction
		, moveActionLeft, delayAction, flipAction1, NULL);

	//auto action = Repeat::create(seqAction, 20);
	auto action = RepeatForever::create(seqAction);
	
	bkqSpr->runAction(action->reverse());

	return true;
}

void ActionScene::update(float dt)
{
	frmTime++;

	//Sprite *bkq = (Sprite*)(getChildByName("bkq"));
	Sprite *bkq = (Sprite*)(getChildByTag(111));
	
	bkq->setPositionX(bkq->getPositionX() + (200/ 60/2));

	if (frmTime >= 60*2)
	{
		unscheduleUpdate();
	}

}