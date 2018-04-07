#pragma once
# include <Siv3D.hpp>

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
//	�o��l���N���X
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class Actor
{
public:
	String	z_name; //���O
	Texture z_face; //��摜
	Texture z_body; //�S�g�摜

public:
	Actor() {}
	virtual ~Actor() {}
	String GetName()const { return z_name; }
	Texture GetFace()const { return z_face; }
	Texture GetBody() const { return z_body; }
};

class ���@�� : public Actor
{
public:
	���@��()
	{
		z_name = L"���@���L�����[";
		z_body = Texture(Image(L"Example/chara_ev_hero_01.png"));
	}
};

class �T�N�� : public Actor
{
public:
	�T�N��()
	{
		z_name = L"�T�N��";
		z_body = Texture(Image(L"Example/chara_ev_other_01.png"));
	}
};