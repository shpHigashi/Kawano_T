#pragma once
#include "Scene.h"

/// <summary>
/// �Q�[���I�[�o�[�V�[��
/// </summary>
class GameplayingScene : public Scene
{
private:
	float px = 0, py = 0;
	float vx = 0, vy = 0;
	
	int playingH_ = -1; // �^�C�g���摜

	static constexpr int fade_interval = 60;
	int fadeTimer_ = fade_interval;
	int fadeValue_ = 255;

	unsigned int fadeColor_ = 0x000000;	// �t�F�[�h�̐F(�f�t�H��)

	void FadeInUpdate(const InputState& input);
	void NormalUpdate(const InputState& input);
	void FadeOutUpdate(const InputState& input);

	using UpdateFunc_t = void (GameplayingScene::*)(const InputState& input);
	UpdateFunc_t updateFunc_ = nullptr;
public:
	GameplayingScene(SceneManager& manager);
	~GameplayingScene() {}
	void Update(const InputState& input);
	void Draw();
};

