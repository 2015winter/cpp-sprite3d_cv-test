#include "loading3dScene.h"

USING_NS_CC;

Scene* loading3dScene::createScene()
{
	auto scene = Scene::create();
	auto layer = loading3dScene::create();
	scene->addChild(layer);
	return scene;
}

bool loading3dScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visiableSize = Director::getInstance()->getVisibleSize();

/*	auto origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::create("BackGround1.png", Rect(0, 0, visiableSize.width, visiableSize.height));

	//Sets the min filter, mag filter, wrap s and wrap t texture parameters
	Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
	bg->getTexture()->setTexParameters(tp);
	bg->setPosition(origin + Vec2(visiableSize.width/2, visiableSize.height/2));
	this->addChild(bg, -1);*/
	auto sprite3d = Sprite3D::create("Sprite3DTest/girl.c3b");
	sprite3d->setScale(1);
	sprite3d->setAnchorPoint(Vec2(0.0, 0.0));
	sprite3d->setPosition(Vec2(visiableSize.width / 2, visiableSize.height / 2));
	this->addChild(sprite3d, 0, "girl");

	auto animation_girl = Animation3D::getOrCreate("Sprite3DTest/girl.c3b");
	if (animation_girl)
	{
		auto animate_girl = Animate3D::create(animation_girl);
		sprite3d->runAction(RepeatForever::create(animate_girl));
	}

	// auto sprite3d_tortoise = Sprite3D::create("Sprite3DTest/tortoise.c3b");
	// sprite3d_tortoise->setScale(0.2);
	// sprite3d_tortoise->setAnchorPoint(Vec2(0.0, 0.0));
	// sprite3d_tortoise->setPosition(Vec2(200, visiableSize.height / 2));
	// this->addChild(sprite3d_tortoise, 1, tutorise_Tag);

	// auto animation_tortoise = Animation3D::getOrCreate("Sprite3DTest/tortoise.c3b");
	// if (animation_tortoise)
	// {
	// 	auto animate_tortoise = Animate3D::create(animation_tortoise);
	// 	animate_tortoise->setSpeed(1.0);
	// 	sprite3d_tortoise->runAction(RepeatForever::create(animate_tortoise));
	// }

	//auto _camera = Camera::createPerspective(60, visiableSize.width / visiableSize.height, 1, 1000);
	//_camera->setPosition3D(Vec3(0.0, 0.0, 220.0));
	//_camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
	//this->addChild(_camera);
	return true;
}

void loading3dScene::onEnter()
{
	Layer::onEnter();
	log("onEnter!");
	auto girl = this->getChildByName("girl");
	auto _eventListenKeyboard = EventListenerKeyboard::create();
	auto _eventListenMouse = EventListenerMouse::create();
	auto _eventListenTouch = EventListenerTouchOneByOne::create();
	_eventListenKeyboard->onKeyPressed = [girl](EventKeyboard::KeyCode pKeyCode, Event * pEvent)
	{
		log("onKeyPressed!");
		switch (pKeyCode)
		{
		case EventKeyboard::KeyCode::KEY_W:
		{
			auto actionW = MoveBy::create(0.22, Vec3(0.0, 0.0, -10.0));
			girl->runAction(actionW);
			break;
		}
		case EventKeyboard::KeyCode::KEY_S:
		{
			auto actionS = MoveBy::create(5, Vec3(-50.0, 0.0, 0.0));
			girl->runAction(actionS);
			break;
		}
		case EventKeyboard::KeyCode::KEY_D:
		{
			auto actionD = MoveBy::create(0.2, Vec3(10.0, 0.0, 0.0));
			girl->runAction(actionD);
			break;
		}
		default:
			break;
		}
	};
	_eventListenMouse->onMouseDown = [](Event* pEvent)
	{
		log("onMouseDown!");
		Event* e = (EventMouse* )pEvent;
	};
	_eventListenMouse->onMouseMove = [](Event* pEvent)
	{
		//log("onMouseMove!");
		Event* e = (EventMouse* )pEvent;
	};
	_eventListenKeyboard->onKeyReleased = [](EventKeyboard::KeyCode pKeyCode, Event* pEvent)
	{
		log("onKeyReleased!");
	};
	_eventListenTouch->onTouchBegan = CC_CALLBACK_2(loading3dScene::onTouchBegan, this);
	_eventListenTouch->onTouchMoved = CC_CALLBACK_2(loading3dScene::onTouchMoved, this);
	_eventListenTouch->onTouchEnded = CC_CALLBACK_2(loading3dScene::onTouchEnded, this);
	/*** 注册监听器 ***/
	//获得事件分发器对象
	EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();
	//注册键盘监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_eventListenKeyboard->clone(), this);
	//注册鼠标监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_eventListenMouse->clone(), this);
	//注册触摸监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_eventListenTouch->clone(), this);
}

bool loading3dScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	log("onTouchBegan!");
	return true;
}

void loading3dScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	log("onTouchMoved!");
	//pEvent->getCurrentTarget()返回类型为Node，强制转换为Sprite*型
	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
	target->setPosition(target->getPosition() + pTouch->getDelta());
}

void loading3dScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

//void loading3dScene::onDraw()
//{
//	//_customcommand->init(_globalZOrder);
//	//_customcommand->func = CC_CALLBACK_0(loading3dScene::shaderTest, this);
//	//Director::getInstance()->getRenderer()->addCommand(_customcommand);
//	Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
//	Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
//	Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
//	Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
//	GLProgram* program = new GLProgram();
//	/*program->initWithFilenames("vert.vsh", "frag.fsh");
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
//	program->link();
//	program->updateUniforms();*/
//	program->use();
//}

//void loading3dScene::shaderTest(Sprite* sprite)
//{
//	if (!sprite)
//	{
//		return;
//	}
//	GLProgram* program = new GLProgram();
//	program->initWithFilenames("vert.vsh", "frag.fsh");
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
//	program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
//	program->link();
//	program->updateUniforms();//it will create 4 uniforms **cocos build-in**  
//}

//void loading3dScene::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
//{
//	Layer::draw(renderer, parentTransform, parentFlags);
//	_customcommand->init(_globalZOrder);
//	_customcommand->func = CC_CALLBACK_0(loading3dScene::onDraw, this);
//	Director::getInstance()->getRenderer()->addCommand(_customcommand);
//}
