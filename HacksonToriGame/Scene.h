#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>

//�V�[����
enum class SceneType
{
	Title,
	Event,
	Battle,
	GameOver,
	GameClear
};

//�V�[�����ړ������Ƃ������Ă����f�[�^
class CommonData
{
public:
	int		battleCount = 0;
	bool	lastBattle = false;
};

using MyScene = SceneManager<SceneType, CommonData>;

