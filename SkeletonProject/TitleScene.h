#pragma once
#include "Scene.h"

// タイトルシーン
class TitleScene : public Scene
{
private:
	static constexpr int fade_interval = 60;

	int titleH_ = -1; // タイトル画像

	int fadeTimer_ = fade_interval;	// フェードタイマー
	int fadeValue_ = 255;	// 黒矩形とのブレンド具合

	void FadeInUpdate(const InputState& input);
	void NormalUpdate(const InputState& input);
	void FadeOutUpdate(const InputState& input);

	void (TitleScene::* updateFunc_)(const InputState& input);

public:
	TitleScene(SceneManager& manager);
	~TitleScene();

	void Update(const InputState& input);
	void Draw();
};

