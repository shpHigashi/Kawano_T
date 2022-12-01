#include"TitleScene.h"
#include"InputState.h"
#include"SceneManager.h"
#include"GameplayingScene.h"
#include "OptionScene.h"
#include "DrawFunctions.h"
#include <DxLib.h>

void TitleScene::FadeInUpdate(const InputState& input)
{
	fadeValue_ = 255 * static_cast<float>(fadeTimer_) / static_cast<float>(fade_interval);
	if (--fadeTimer_ == 0)
	{
		updateFunc_ = &TitleScene::NormalUpdate;
		fadeValue_ = 0;
	}
}

void TitleScene::NormalUpdate(const InputState& input)
{
	if (input.IsTriggered(InputType::next))
	{
		updateFunc_ = &TitleScene::FadeOutUpdate;
	}
	if (input.IsTriggered(InputType::prev))
	{
		manager_.ChangeScene(new OptionScene(manager_));
		return;
	}
}

void TitleScene::FadeOutUpdate(const InputState& input)
{
	fadeValue_ = 255 * static_cast<float>(fadeTimer_) / static_cast<float>(fade_interval);
	if (++fadeTimer_ == fade_interval)
	{
		manager_.ChangeScene(new GameplayingScene(manager_));
		return;
	}

}

TitleScene::TitleScene(SceneManager& manager) :Scene(manager) ,updateFunc_(&TitleScene::FadeInUpdate)
{
	titleH_ = my::MyLoadGraph(L"rime.jpg");
}

TitleScene::~TitleScene()
{
	DeleteGraph(titleH_);
}

void TitleScene::Update(const InputState& input)
{
	(this->*updateFunc_)(input);
}

void TitleScene::Draw()
{
	DrawRotaGraph(240, 240, 1.0f, 0.0f, titleH_, true);
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeValue_);
	DrawBox(0, 0, 640, 480, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}