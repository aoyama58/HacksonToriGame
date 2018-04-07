#pragma once
#include"Scene.h"
#include"Actor.h"
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�C�x���g�V�[���N���X.h
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class EventScene : public MyScene::Scene
{
private:
	const Sound		z_BGM		= Sound(L"Example/�t���C������̗J�T.mp3");
	const Texture	z_BGTexture	= Texture(Image(L"Example/bg_image_01.jpg"));
	const Font		z_font		= Font(30);

	�T�N�� sakuya;
	���@�� val;

public:
	void init	() override;
	void update	() override;
	void draw	() const override;
};