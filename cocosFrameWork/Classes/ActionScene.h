#ifndef __ACTION_SCENE_H__
#define __ACTION_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ActionScene : public Scene{

private:
	int  frmTime;
public:
	virtual bool init();
	virtual void update(float dt);


	void endFunction();

	CREATE_FUNC(ActionScene);
};


#endif // !__ACTION_SCENE_H__
