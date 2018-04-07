#pragma once
#include"Scene.h"

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o�g���V�[���p�t�H���g�ꗗ
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\





//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�J�[�h�̑���
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
enum struct CardType
{
	Normal,
	Zero,
	Tori,
	Counter,
	OddKiller,
	EvenKiller,
	UltimateKushi
};


//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�J�[�h�f�[�^
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
struct CardData
{
	CardType	type;
	int			cost;
	int			power;
	bool		canUse;
	bool		isSelected;
	Rect		rect;
	const Font	costFont =Font(10);
	const Font	powerFont=Font(15);
	

	void draw()const
	{
		switch (type)
		{
		case CardType::Normal:
			rect.draw(Palette::White);
			powerFont(power).drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::Zero:
			rect.draw(Palette::White);
			powerFont(power).drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::Tori:
			rect.draw(Palette::Yellow);
			powerFont(power).drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::Counter:
			rect.draw(Palette::Aqua);
			powerFont(L"�����").drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::OddKiller:
			rect.draw(Palette::Aqua);
			powerFont(L"��װ").drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::EvenKiller:
			rect.draw(Palette::Aqua);
			powerFont(L"�����װ").drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		case CardType::UltimateKushi:
			rect.draw(Palette::Pink);
			powerFont(L"�`���̋�").drawCenter(rect.center + Point{ 0, 10 }, Palette::Black);
			break;
		default:
			break;
		}

		if(!canUse)
			rect.draw(Palette::Gray);
		rect.drawFrame(0, 1, isSelected ? Palette::Blue : Palette::Black);
		costFont(cost).drawCenter(rect.center + Point{ 0, -20 }, Palette::Black);
	}
};

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o�g���t�F�[�Y
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
enum struct BattlePhase
{
	GuidanceA,
	ThreeCardSelect,
	GuidanceB,
	BattleCardSelect,
	BattlePhase,
	Victory,
	Lose,
	CostOverGuidance
};


//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o�g���V�[���N���X
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class BattleScene : public MyScene::Scene
{
private:
	std::vector<CardData> z_deck;
	std::vector<CardData> z_battleDeck;
	std::vector<CardData> z_enemyBattleDeck;
	CardData	z_battleCard;
	Font g_guidFont = Font(40);
	BattlePhase z_phase;
	int z_round;
	int z_counter;
	int z_selectedCount;

public:
	void init	() override;
	void update	() override;
	void draw	() const override;
};