#include "PauseScene.h"
#include "InputState.h"
#include "SceneManager.h"
#include "KeyConfigScene.h"
#include "Dxlib.h"

PauseScene::PauseScene(SceneManager& manager) : Scene(manager)
{
}

PauseScene::~PauseScene()
{
}

void PauseScene::Update(const InputState& input)
{
	if (input.IsTriggered(InputType::pause))
	{
		manager_.PopScene();
		return;
	}
	if (input.IsTriggered(InputType::keyconfig))
	{
		manager_.PushScene(new KeyConfigScene(manager_));
	}
}

void PauseScene::Draw()
{
	//DrawString(50, 50, L"Pausing...", 0xffff88);

	constexpr int pw_width = 400;
	constexpr int pw_height = 300;
	constexpr int pw_start_x = (480 - pw_width) / 2;
	constexpr int pw_start_y = (480 - pw_height) / 2;

	SetDrawBlendMode(DX_BLENDMODE_MULA, 128);
	
	// ポーズウィンドウセロファン(黒)
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0x000000, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// ポーズ中メッセージ
	DrawString(pw_start_x + 10, pw_start_y + 10, L"ポーズ中..", 0xffff88);

	// ポーズウィンドウ枠線
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0xffffff, false);
}
