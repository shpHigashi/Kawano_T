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

	// �t�F�[�h�C������update�֐�
	void FadeInUpdate(const InputState& input);
	// �ʏ��Ԃ�update�֐�
	void NormalUpdate(const InputState& input);
	// �t�F�[�h�A�E�g����update�֐�
	void FadeOutUpdate(const InputState& input);

	// update�p�����o�֐��|�C���^
	void (TitleScene::* updateFunc_)(const InputState& input);

public:
	TitleScene(SceneManager& manager);
	~TitleScene();

	void Update(const InputState& input);
	void Draw();
};

