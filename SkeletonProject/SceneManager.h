#pragma once

// �v���g�^�C�v�錾
class Scene;
class InputState;

// �V�[���Ď��N���X
class SceneManager
{
private:
	// �����s���̃V�[����؂�ւ��Ă��������̂�
	// �Q�Ƃł͂Ȃ��|�C���^�Ƃ��Đ錾
	Scene* scene_ = nullptr;

public:
	// �V�[���̐؂�ւ����s��
	void ChangeScene(Scene* scene);

	// �e�V�[���̍X�V���s��( ���̓X�e�[�g�̎Q�� )
	void Update(const InputState& input);

	// �e�V�[���̕`����s��
	void Draw();
};