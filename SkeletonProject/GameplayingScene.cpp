#include "GameplayingScene.h"
#include "InputState.h"
#include "GameoverScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "PauseScene.h"
#include "DrawFunctions.h"
#include <DxLib.h>

void GameplayingScene::FadeInUpdate(const InputState& input)
{
	fadeValue_ = 255 * static_cast<float>(fadeTimer_) / static_cast<float>(fade_interval);
	if (--fadeTimer_ == 0)
	{
		updateFunc_ = &GameplayingScene::NormalUpdate;
	}
}

void GameplayingScene::NormalUpdate(const InputState& input)
{
	vy += 0.05f;
	py += vy;
	
	if (py >= 400)
	{
		vy = -5;
	}

	if (input.IsTriggered(InputType::next))
	{
		updateFunc_ = &GameplayingScene::FadeOutUpdate;
		fadeColor_ = 0xFF0000;
	}
	else if (input.IsTriggered(InputType::prev))
	{
		manager_.ChangeScene(new TitleScene(manager_));
		return;
	}
	else if (input.IsTriggered(InputType::pause))
	{
		manager_.PushScene(new PauseScene(manager_));
		return;
	}
}

void GameplayingScene::FadeOutUpdate(const InputState& input)
{
	fadeValue_ = 255 * static_cast<float>(fadeTimer_) / static_cast<float>(fade_interval);
	if (++fadeTimer_ == fade_interval)
	{
		manager_.ChangeScene(new GameoverScene(manager_));
		return;
	}
}

GameplayingScene::GameplayingScene(SceneManager& manager) : Scene(manager) ,updateFunc_(&GameplayingScene::FadeInUpdate)
{
	playingH_ = my::MyLoadGraph(L"rime.jpg");
	px = 240;
	py = 400;
	vx = 0;
	vy = 0;
}

void GameplayingScene::Update(const InputState& input)
{
	(this->*updateFunc_)(input);
}

void GameplayingScene::Draw()
{
	DrawRotaGraph(240, 240, 1.0f, DX_PI, playingH_, true);
	DrawCircle(px, py, 20, 0xF0E68C, true);
	SetDrawBlendMode(DX_BLENDMODE_MULA, fadeValue_);
	DrawBox(0, 0, 640, 480, fadeColor_, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}