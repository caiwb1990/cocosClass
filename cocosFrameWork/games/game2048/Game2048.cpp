
#include "../../Classes/common/common.h"
#include "Game2048.h"


bool Game2048::init()
{
	CCLOG("Game2048::init()");
	if (!Scene::init())
	{
		return false;
	}

	initUI();
	
	initData();

	return true;
}

static int s_row = 4;

void Game2048::initUI()
{
	//scene -> gameLayer -> root / uiNode
	LayerColor *gameLayer = LayerColor::create(Color4B(0xff, 0xff, 0xf0, 0xff));
	this->addChild(gameLayer);

	Node *root = Node::create();
	gameLayer->addChild(root);

	Node *uiNode = Node::create();
	gameLayer->addChild(uiNode);

	lblScore = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	lblScore->setPosition(Vec2(DISPLAY_CX, DISPLAY_HEIGHT * 4 / 5));
	uiNode->addChild(lblScore);

	//root -> bg 
	bgSize = DISPLAY_WIDTH - offsetW;

	LayerColor *bgLayer = LayerColor::create(Color4B(0xcd, 0xba, 0x96, 0xff), bgSize, bgSize);
	bgLayer->setPosition(Point(DISPLAY_CX,DISPLAY_CY));
	bgLayer->setAnchorPoint(Point(0.5, 0.5));
	bgLayer->ignoreAnchorPointForPosition(false);
	root->addChild(bgLayer);

	//NumNode
	numSize = (bgSize - offsetW) / s_row ;

	for (int i = 0; i < s_row; i++)
	{
		for (int j = 0; j < s_row; j++)
		{
			int numberX = numSize*(i+0.5) + DISPLAY_CX - bgSize/2 + offsetW/2 ;
			int numberY = numSize*(j+0.5) + DISPLAY_CY - bgSize/2 + offsetW/2;

			Node *numNode = Node::create();
			numNode->setPosition(Point(numberX, numberY));
			root->addChild(numNode);

			//bg
			LayerColor *numBg = LayerColor::create(Color4B(200, 190, 180, 0xff), numSize-offsetW/2, numSize-offsetW/2);
			numBg->setAnchorPoint(Point(0.5, 0.5));
			numBg->ignoreAnchorPointForPosition(false);
			numNode->addChild(numBg);

			//card
			cardNumbers[i][j] = 0;
			Node *cardNode = createNumCard(cardNumbers[i][j]);
			cardNodes[i][j] = cardNode;

			numNode->addChild(cardNode);
		}
	}

	randomCreateNum();
	randomCreateNum();

}

void Game2048::randomCreateNum()
{
	int i = CCRANDOM_0_1() * s_row;
	int j = CCRANDOM_0_1() * s_row;

	if (cardNumbers[i][j] <= 0)
	{
		cardNumbers[i][j] = (CCRANDOM_0_1() * 10 < 5) ? 2 : 4;
		setCardNodeNumber(cardNodes[i][j], cardNumbers[i][j]);
	}
	else
	{
		randomCreateNum();
	}
}

Node* Game2048::createNumCard(int curNumber)
{
	Node *cardNode = Node::create();

	auto cardBg = LayerColor::create(Color4B(0xff, 0xfa, 0xcd, 0xff), numSize-offsetW, numSize-offsetW);
	cardBg->ignoreAnchorPointForPosition(false);
	cardBg->setAnchorPoint(Point(0.5, 0.5));
	cardNode->addChild(cardBg);

	auto lblNum = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	
	lblNum->setName("lblName");
	cardNode->addChild(lblNum);

	setCardNodeNumber(cardNode, curNumber);

	return cardNode;
}

void Game2048::setCardNodeNumber(Node* nodeCard ,int number)
{

	char string[12] = { 0 };
	sprintf(string, "%d", number);
	((Label*)nodeCard->getChildByName("lblName"))->setString(string);
	nodeCard->setVisible(number>0);
}

void Game2048::initData()
{
	curScore = 0;
	char string[12] = { 0 };
	sprintf(string, "%d", curScore );
	lblScore->setString(string);
}
//node 的生命周期方法
void Game2048::onEnter()
{
	CCLOG("Game2048::onEnter()");

	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = CC_CALLBACK_2(Game2048::onTouchBegan,this);
	_listener->onTouchMoved = CC_CALLBACK_2(Game2048::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(Game2048::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
	
	Scene::onEnter();
}

//监听是成对出现的 注册了 就得remove
void Game2048::onExit()
{
	CCLOG("Game2048::onExit()");

	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

 bool Game2048::onTouchBegan(Touch *touch, Event *unused_event)
{
	 CCLOG("Game2048::onTouchBegan");

	 startPoint = touch->getLocation();
	 
	 return true;
}
 void Game2048::onTouchMoved(Touch *touch, Event *unused_event)
 {
	// CCLOG("Game2048::onTouchMoved");

 }
 void Game2048::onTouchEnded(Touch *touch, Event *unused_event)
{
	 CCLOG("Game2048::onTouchEnded");
	 Vec2 endPoint = touch->getLocation();
	 Vec2 dVec = endPoint - startPoint;

	 CCLOG("point %f,%f", dVec.x, dVec.y);
	 //判断是X轴 还是Y轴的偏移
	 if (abs(dVec.x) < abs(dVec.y)  ) 
	 {
		 if (dVec.y > 1)
		 {
			 CCLOG("up up up");
		 }
		 else if (dVec.y < -1)
		 {
			 CCLOG("down down down ");
		 }
	 }
	 else
	 {
		 if (dVec.x > 1)
		 {
			 CCLOG("right right right");
		 }
		 else if (dVec.x < -1)
		 {
			 CCLOG("left left left");
		 }
	 }
	


}