#include "common.h"
#include "InputState.h"
#include "KeyConfigScene.h"
#include "SceneManager.h"


KeyConfigScene::KeyConfigScene(SceneManager& manager) : Scene(manager)
{

}

void KeyConfigScene::Update(const InputState& input)
{
	if (input.IsTriggered(InputType::keyconfig))
	{
		manager_.PopScene();
		return;
	}
}

void KeyConfigScene::Draw()
{
	constexpr int pw_width = 400;	// キーコンフィグ枠の幅
	constexpr int pw_height = 300;	// キーコンフィグ枠の高さ
	constexpr int pw_start_x = (480 - pw_width) / 2 + 15;	// キーコンフィグ枠左
	constexpr int pw_start_y = (480 - pw_height) / 2 + 15;	// キーコンフィグ枠上

	// キーコンフィグ背景
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0xf797cb, true);

	// キーコンフィグメッセージ
	DrawString(pw_start_x + 10, pw_start_y + 10, L"けーこんふぇぐ", 0xffff88);

	// キーコンフィグウィンドウ枠線
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0xffffff, false);
}
