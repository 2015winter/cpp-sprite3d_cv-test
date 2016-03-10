#ifndef __LOADING3DSCENE_H__
#define __LOADING3DSCENE_H__

#include "cocos2d.h"
using namespace std;
USING_NS_CC;

typedef enum SpriteTags
{
	girl_Tag = 101,
	tutorise_Tag
};


class loading3dScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(loading3dScene);
	//void onDraw();
	//void shaderTest(Sprite* sprite);
	//CustomCommand* _customcommand;
private:
	bool keyState = false;
	Vec2 _beginPos; //Cursor position that begin click down 
	void onEnter() override;
	//void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);

public:
	bool onTouchBegan(Touch* pTouch, Event* pTvent);
	void onTouchMoved(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);
};
#endif