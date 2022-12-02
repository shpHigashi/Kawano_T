#pragma once

//#include "common.h"
#include<deque>

// �v���g�^�C�v�錾
class Scene;
class InputState;

// �V�[���Ď��N���X
class SceneManager
{
private:
	// �����s���̃V�[����؂�ւ��Ă��������̂�
	// �Q�Ƃł͂Ȃ��|�C���^�Ƃ��Đ錾
	std::deque<Scene*> scenes_;

public:
	// �V�[���̐؂�ւ����s��
	void ChangeScene(Scene* scene);

	// �V�[������ɐς�
	// update�Ŏ��������̂͏�ɐς܂ꂽ�V�[���̂�
	void PushScene(Scene* scene);

	// ��ԏ�̃V�[�����폜����
	// �������A���̌��ʃX�^�b�N����ɂȂ邱�Ƃ̂Ȃ��悤��
	void PopScene();

	// �e�V�[���̍X�V���s��( ���̓X�e�[�g�̎Q�� )
	void Update(const InputState& input);

	// �e�V�[���̕`����s��
	void Draw();
};