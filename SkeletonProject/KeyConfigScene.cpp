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
	constexpr int pw_width = 400;	// �L�[�R���t�B�O�g�̕�
	constexpr int pw_height = 300;	// �L�[�R���t�B�O�g�̍���
	constexpr int pw_start_x = (480 - pw_width) / 2 + 15;	// �L�[�R���t�B�O�g��
	constexpr int pw_start_y = (480 - pw_height) / 2 + 15;	// �L�[�R���t�B�O�g��

	// �L�[�R���t�B�O�w�i
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0xf797cb, true);

	// �L�[�R���t�B�O���b�Z�[�W
	DrawString(pw_start_x + 10, pw_start_y + 10, L"���[����ӂ���", 0xffff88);

	// �L�[�R���t�B�O�E�B���h�E�g��
	DrawBox(pw_start_x, pw_start_y, pw_start_x + pw_width, pw_start_x + pw_height, 0xffffff, false);
}
