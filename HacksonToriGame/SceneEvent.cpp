#include"SceneEvent.h"


//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�C�x���g�V�[���N���X.cpp
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
void EventScene::init()
{
	//�T�E���h�ݒ�
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
	//���C��1
	z_BGTexture.draw();

	//���C��2
	val.GetBody().mirror().draw(10, 10);
	sakuya.GetBody().draw(400, 10);
}
