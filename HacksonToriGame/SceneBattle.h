#pragma once
#include"Scene.h"

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o�g���V�[���N���X.h
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class BattleScene : public MyScene::Scene
{
private:
public:
	void init	() override;
	void update	() override;
	void draw	() const override;
};