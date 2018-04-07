# include <Siv3D.hpp>
#include"SceneTitle.h"
#include"SceneEvent.h"
#include"SceneBattle.h"

void Main()
{
	Window::Resize(800, 600);

	MyScene scene;
	scene.add<TitleScene>(SceneType::Title);
	scene.add<EventScene>(SceneType::Event);
	scene.add<BattleScene>(SceneType::Battle);

	while (System::Update())
	{
		scene.updateAndDraw();
	}
}
