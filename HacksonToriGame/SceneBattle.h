#pragma once
#include"Scene.h"

//―――――――――――――――――――――――――
//	バトルシーンクラス.h
//―――――――――――――――――――――――――
class BattleScene : public MyScene::Scene
{
private:
public:
	void init	() override;
	void update	() override;
	void draw	() const override;
};