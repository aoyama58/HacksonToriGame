#include "SceneBattle.h"
void BattleScene::init()
{
	//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
	//	���J�[�h���Z�b�g
	//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
	//�ʏ�J�[�h
	for (int i = 0; i < 10; ++i)
	{
		CardData card;
		//����
		card.type = CardType::Normal;
		//�R�X�g
		if (i < 4)
		{
			card.cost = 1;
		}
		else if (i < 7)
		{
			card.cost = 2;
		}
		else
		{
			card.cost = 3;
		}
		//�p���[
		card.power = i + 1;
		//�g�p�\��
		card.canUse = true;
		//�I�𒆂�
		card.isSelected = false;
		//�ꏊ
		card.rect = Rect(200 + 5 + 85 * (i % 5), 400 + 5 + static_cast<int>(i / 5) * 65, 80, 60);
		z_deck.push_back(card);
	}
	//�R�X�g0�J�[�h
	for (int i = 0; i < 3; ++i)
	{
		CardData card;
		card.type = CardType::Zero;
		card.cost = 0;
		card.power = 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect = Rect(200 + 5 + 85 * i , 400 + 5 + 2 * 65, 80, 60);
		z_deck.push_back(card);
	}
	//����J�[�h
	{
		//��װ
		CardData card;
		card.type = CardType::OddKiller;
		card.cost = 2;
		card.power = 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect = Rect(200 + 5 + 85 * 5, 400 + 5 + 65 * 0, 80, 60);
		z_deck.push_back(card);

	}
	{
		//�����װ
		CardData card;
		card.type = CardType::EvenKiller;
		card.cost = 2;
		card.power = 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect = Rect(200 + 5 + 85 * 6, 400 + 5 + 65 * 0, 80, 60);
		z_deck.push_back(card);

	}
	{
		//�J�E���^�[
		CardData card;
		card.type	= CardType::Counter;
		card.cost	= 2;
		card.power	= 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect	= Rect(200 + 5 + 85 * 5, 400 + 5 + 65 * 1, 80, 60);
		z_deck.push_back(card);

	}
	{
		//�`���̋�
		CardData card;
		card.type = CardType::UltimateKushi;
		card.cost = 1;
		card.power = 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect = Rect(200 + 5 + 85 * 6, 400 + 5 + 65 * 1, 80, 60);
		z_deck.push_back(card);
	}
	//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
	//	�����̑�
	//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\

	z_phase = BattlePhase::GuidanceA;
	z_round = 1;
	z_counter = 0;
	z_selectedCount = 0;
}

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o�g���̗���
//
//	�t�F�[�Y1
//		��D����R���I��
//		���łɑI�񂾃J�[�h�͑I�ׂȂ���
//		�I�񂾃J�[�h�̃R�X�g�̍��v��4�ȉ��łȂ��Ƃ��߂�
//
//	�t�F�[�Y2
//		�I�񂾂R�������݂��ɏ�ɏo��
//		�R���̒�����키�J�[�h���P���I��
//		���肪�ǂ̃J�[�h��I�Ԃ��A�m�����\������Ă��邼
//		
//	�t�F�[�Y3�@�o�g��
//		���݂��ɑI�񂾃J�[�h�Ńo�g�����s����
//		�J�[�h�ɂ�4��ނ��邼
//			�E�ʏ�J�[�h	�F�w�i���������B�R�X�g�ƃp���[�������Ă���B�傫���ق����p���[���B
//			�E���J�[�h		�F�w�i�����F�����B������J�[�h�𖳌�������B����p�J�[�h��
//			�E����J�[�h	�F�w�i�������B�R�X�g�Ɩ��O�������Ă���B�����Ȍ��ʂ����邼�B
//			�E�`���̋��J�[�h�F�w�i���Ԃ����B���J�[�h���m��œ|���B���J�[�h�ȊO�ɂ͌��ʂ��Ȃ����B
//
//		�o�g���ɏ��ƁA�g�p�����J�[�h�̃R�X�g���̓_��������B
//		�`���̋��œ|�����ꍇ�͓��ʂɂS�_���邼�B���ꂵ���ȁB
//		�����܂ł��P���E���h���B
//
//	�v5���E���h�s���A�_���̍��������������B
//	�������A�_���������ꍇ�̓v���[���[�̕����ƂȂ�B�n���f���Ă킯��
//
//
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
void BattleScene::update()
{
	switch (z_phase)
	{
	case BattlePhase::GuidanceA:
		if (120 < z_counter)
		{
			z_phase = BattlePhase::ThreeCardSelect;
			z_counter = 0;
		}
		++z_counter;
		break;
	case BattlePhase::ThreeCardSelect:
		if (z_selectedCount == 3)
		{
			z_phase = BattlePhase::GuidanceB;
			z_counter = 0;
			for (auto& card : z_deck)
			{
				if (card.isSelected)
				{
					card.isSelected = false;
					card.canUse = false;
					continue;
				}
			}
		}
		//�N���b�N���ĂȂ���Ζ���
		if (!Input::MouseL.clicked)
			return;
		for (auto& card : z_deck)
		{
			if (card.rect.leftClicked)
			{
				//�g�p�ł��Ȃ���Ζ���
				if (!card.canUse)
					return;
				//�I�𒆂Ȃ�I��������
				if (card.isSelected)
				{
					card.isSelected = false;
					--z_selectedCount;
					return;
				}
				//�I�𒆂łȂ��Ȃ�I������
				card.isSelected = true;
				++z_selectedCount;
			}
		}
		break;
	case BattlePhase::GuidanceB:
		if (120 < z_counter)
		{
			z_phase = BattlePhase::BattleCardSelect;
			z_counter = 0;
		}
		++z_counter;
		break;
	case BattlePhase::BattleCardSelect:

		break;
	case BattlePhase::BattlePhase:
		break;
	case BattlePhase::Victory:
		break;
	case BattlePhase::Lose:
		break;
	default:
		break;
	}
}

void BattleScene::draw() const
{
	//���C���[1 (�w�i)
	Color color;
	Rect PlayerDataField(0, 0, 200, 600);
	color = Palette::Greenyellow;
	color.a = 80;
	PlayerDataField.draw(color).drawFrame(1, 0, Palette::Black);
	Rect EnemyHandField(200, 0, 600, 200);
	color = Palette::Aqua;
	color.a = 80;
	EnemyHandField.draw(color).drawFrame(0, 1, Palette::Black);
	Rect YourHandField(200, 400, 600, 200);
	YourHandField.draw(color).drawFrame(0, 1, Palette::Black);
	
	//���C���[2�@�J�[�h
	for (auto& card : z_deck)
	{
		card.draw();
	}

	//���C���[�R�@�K�C�_���X
	switch (z_phase)
	{
	case BattlePhase::GuidanceA:
	{
		Rect guidanceArea(0, 150, 800, 300);
		guidanceArea.draw(Palette::Whitesmoke);
		guidanceArea.drawFrame(0, 5, Palette::Black);
		g_guidFont(L"�J�[�h���R���I�ׁI").drawCenter(guidanceArea.center, Palette::Black);
		break;
	}
	case BattlePhase::ThreeCardSelect:
		break;
	case BattlePhase::GuidanceB:
	{
		if (z_counter < 30)
			return;
		Rect guidanceArea(0, 150, 800, 300);
		guidanceArea.draw(Palette::Whitesmoke);
		guidanceArea.drawFrame(0, 5, Palette::Black);
		g_guidFont(L"�o�g���J�[�h��I�ׁI").drawCenter(guidanceArea.center, Palette::Black);
		break;
	}
	case BattlePhase::BattleCardSelect:
		break;
	case BattlePhase::BattlePhase:
		break;
	case BattlePhase::Victory:
		break;
	case BattlePhase::Lose:
		break;
	default:
		break;
	}
}
