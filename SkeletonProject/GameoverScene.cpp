#include "GameoverScene.h"
#include "InputState.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include <DxLib.h>

void GameoverScene::Update(const InputState& input)
{
	if (input.IsTriggered(InputType::next))
	{
		manager_.ChangeScene(new TitleScene(manager_));
		return;
	}
}

void GameoverScene::Draw()
{
	DrawString(300, 200, L"GameOverScene", 0xfffff);
}