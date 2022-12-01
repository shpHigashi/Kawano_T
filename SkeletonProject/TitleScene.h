#pragma once
#include "Scene.h"

// �^�C�g���V�[��
class TitleScene : public Scene
{
private:
	static constexpr int fade_interval = 60;

	int titleH_ = -1; // �^�C�g���摜

	int fadeTimer_ = fade_interval;	// �t�F�[�h�^�C�}�[
	int fadeValue_ = 255;	// ����`�Ƃ̃u�����h�

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

