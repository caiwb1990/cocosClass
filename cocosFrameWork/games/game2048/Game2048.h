#ifndef __GAME_2048_H__
#define __GAME_2048_H__

#include "cocos2d.h"
USING_NS_CC;

class Game2048 : public Scene
{

private:
	EventListenerTouchOneByOne *_listener;
	Vec2 startPoint;
	Label *lblScore;
	int curScore;

	int bgSize = 0;
	int offsetW = 20;
	int numSize = 0;

	void initUI();
	void initData();

	Node* createNumCard(int curNumber);
	void randomCreateNum();
	void setCardNodeNumber(Node* nodeCard,int number);

	int cardNumbers[4][4];
	Node* cardNodes[4][4];

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
public:
	virtual bool init();

	CREATE_FUNC(Game2048);
};


#endif