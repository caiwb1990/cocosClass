#ifndef __COMMON_H__
#define __COMMON_H__

#include "cocos2d.h"
USING_NS_CC;

#define DISPLAY_SIZE (Director::getInstance()->getWinSize())
#define DISPLAY_WIDTH (DISPLAY_SIZE.width)
#define DISPLAY_HEIGHT (DISPLAY_SIZE.height)

#define DISPLAY_CX (DISPLAY_WIDTH * 0.5f)
#define DISPLAY_CY (DISPLAY_HEIGHT * 0.5f)


#endif