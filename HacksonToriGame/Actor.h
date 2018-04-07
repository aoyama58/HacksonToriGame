#pragma once
# include <Siv3D.hpp>

//―――――――――――――――――――――――――
//	登場人物クラス
//―――――――――――――――――――――――――
class Actor
{
public:
	String	z_name; //名前
	Texture z_face; //顔画像
	Texture z_body; //全身画像

public:
	Actor() {}
	virtual ~Actor() {}
	String GetName()const { return z_name; }
	Texture GetFace()const { return z_face; }
	Texture GetBody() const { return z_body; }
};

class ヴァル : public Actor
{
public:
	ヴァル()
	{
		z_name = L"ヴァルキュリー";
		z_body = Texture(Image(L"Example/chara_ev_hero_01.png"));
	}
};

class サクヤ : public Actor
{
public:
	サクヤ()
	{
		z_name = L"サクヤ";
		z_body = Texture(Image(L"Example/chara_ev_other_01.png"));
	}
};