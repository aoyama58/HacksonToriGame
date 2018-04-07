#include "SceneBattle.h"
void BattleScene::init()
{
	//―――――――――――――――――――――――――
	//	■カードをセット
	//―――――――――――――――――――――――――
	//通常カード
	for (int i = 0; i < 10; ++i)
	{
		CardData card;
		//属性
		card.type = CardType::Normal;
		//コスト
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
		//パワー
		card.power = i + 1;
		//使用可能か
		card.canUse = true;
		//選択中か
		card.isSelected = false;
		//場所
		card.rect = Rect(200 + 5 + 85 * (i % 5), 400 + 5 + static_cast<int>(i / 5) * 65, 80, 60);
		z_deck.push_back(card);
	}
	//コスト0カード
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
	//特殊カード
	{
		//奇数ｷﾗｰ
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
		//偶数ｷﾗｰ
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
		//カウンター
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
		//伝説の串
		CardData card;
		card.type = CardType::UltimateKushi;
		card.cost = 1;
		card.power = 0;
		card.canUse = true;
		card.isSelected = false;
		card.rect = Rect(200 + 5 + 85 * 6, 400 + 5 + 65 * 1, 80, 60);
		z_deck.push_back(card);
	}
	//―――――――――――――――――――――――――
	//	■その他
	//―――――――――――――――――――――――――

	z_phase = BattlePhase::GuidanceA;
	z_round = 1;
	z_counter = 0;
	z_selectedCount = 0;
}

//―――――――――――――――――――――――――
//	バトルの流れ
//
//	フェーズ1
//		手札から３枚選ぶ
//		すでに選んだカードは選べないぞ
//		選んだカードのコストの合計は4以下でないとだめだ
//
//	フェーズ2
//		選んだ３枚をお互いに場に出す
//		３枚の中から戦うカードを１枚選ぶ
//		相手がどのカードを選ぶか、確率が表示されているぞ
//		
//	フェーズ3　バトル
//		お互いに選んだカードでバトルを行うぞ
//		カードには4種類あるぞ
//			・通常カード	：背景が白いぞ。コストとパワーが書いてある。大きいほうがパワーだ。
//			・鳥カード		：背景が黄色いぞ。青い特殊カードを無効かする。鳥専用カードだ
//			・特殊カード	：背景が青いぞ。コストと名前が書いてある。いろんな効果があるぞ。
//			・伝説の串カード：背景が赤いぞ。鳥カードを確定で倒す。鳥カード以外には効果がないぞ。
//
//		バトルに勝つと、使用したカードのコスト分の点数が入る。
//		伝説の串で倒した場合は特別に４点入るぞ。うれしいな。
//		ここまでが１ラウンドだ。
//
//	計5ラウンド行い、点数の高い方が勝利だ。
//	ただし、点数が同じ場合はプレーヤーの負けとなる。ハンデってわけだ
//
//
//―――――――――――――――――――――――――
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
		//クリックしてなければ無視
		if (!Input::MouseL.clicked)
			return;
		for (auto& card : z_deck)
		{
			if (card.rect.leftClicked)
			{
				//使用できなければ無視
				if (!card.canUse)
					return;
				//選択中なら選択を解除
				if (card.isSelected)
				{
					card.isSelected = false;
					--z_selectedCount;
					return;
				}
				//選択中でないなら選択する
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
	//レイヤー1 (背景)
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
	
	//レイヤー2　カード
	for (auto& card : z_deck)
	{
		card.draw();
	}

	//レイヤー３　ガイダンス
	switch (z_phase)
	{
	case BattlePhase::GuidanceA:
	{
		Rect guidanceArea(0, 150, 800, 300);
		guidanceArea.draw(Palette::Whitesmoke);
		guidanceArea.drawFrame(0, 5, Palette::Black);
		g_guidFont(L"カードを３枚選べ！").drawCenter(guidanceArea.center, Palette::Black);
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
		g_guidFont(L"バトルカードを選べ！").drawCenter(guidanceArea.center, Palette::Black);
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
