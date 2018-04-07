#pragma once
#include"Scene.h"

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�^�C�g���V�[���N���X
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class TitleScene : public MyScene::Scene
{
private:
	const Sound		z_BGM		= Sound(L"Example/���h���V��.mp3");
	const Texture	z_BGTexture	= Texture(Image(L"Example/Title_image.png"));
	const String	z_titleText	= String(L"�N���b�N�ŃQ�[���J�n�I");
	Stopwatch		z_stopwatch;	//0~10,000
	const Font		z_font		= Font(30);

public:
	void init() override
	{
		//�T�E���h�ݒ�
		z_BGM.setLoop(true);
		z_BGM.play();
		//�X�g�b�v�E�H�b�`�ݒ�
		z_stopwatch.restart();
		Graphics::SetBackground(Palette::Mintcream);
	}
	void update() override
	{
		if (Input::MouseL.clicked || Input::KeyEnter.clicked)
		{
			changeScene(SceneType::Event);
		}
	}
	void draw() const override
	{
		Rect(50, 100, 700, 200)(z_BGTexture).draw();
		//�^�C�g���e�L�X�g���`�J�`�J�\��������
		if (z_stopwatch.ms() % 2000 < 1300)
		{
			z_font(z_titleText).drawCenter(400, 400, Palette::Aqua);
		}
	}
};