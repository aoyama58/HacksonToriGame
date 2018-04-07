#include"SceneEvent.h"


//―――――――――――――――――――――――――
//	イベントシーンクラス.cpp
//―――――――――――――――――――――――――
void EventScene::init()
{
	//サウンド設定
	z_BGM.setLoop(true);
	z_BGM.play();
}

void EventScene::update()
{
	if (Input::MouseL.clicked || Input::KeyEnter.clicked)
	{
		changeScene(SceneType::Battle);
	}
}

void EventScene::draw() const
{
	//レイヤ1
	z_BGTexture.draw();

	//レイヤ2
	val.GetBody().mirror().draw(10, 10);
	sakuya.GetBody().draw(400, 10);
}
