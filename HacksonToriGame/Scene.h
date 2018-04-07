#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>

//シーン名
enum class SceneType
{
	Title,
	Event,
	Battle,
	GameOver,
	GameClear
};

//シーンを移動したとき持っていくデータ
class CommonData
{
public:
	int		battleCount = 0;
	bool	lastBattle = false;
};

using MyScene = SceneManager<SceneType, CommonData>;

