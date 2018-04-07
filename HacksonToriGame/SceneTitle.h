#pragma once
#include"Scene.h"

//―――――――――――――――――――――――――
//	タイトルシーンクラス
//―――――――――――――――――――――――――
class TitleScene : public MyScene::Scene
{
private:
	const Sound		z_BGM		= Sound(L"Example/ゆるドラシル.mp3");
	const Texture	z_BGTexture	= Texture(Image(L"Example/Title_image.png"));
	const String	z_titleText	= String(L"クリックでゲーム開始！");
	Stopwatch		z_stopwatch;	//0~10,000
	const Font		z_font		= Font(30);

public:
	void init() override
	{
		//サウンド設定
		z_BGM.setLoop(true);
		z_BGM.play();
		//ストップウォッチ設定
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
		//タイトルテキストをチカチカ表示させる
		if (z_stopwatch.ms() % 2000 < 1300)
		{
			z_font(z_titleText).drawCenter(400, 400, Palette::Aqua);
		}
	}
};