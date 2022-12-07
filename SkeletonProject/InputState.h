#pragma once

#include <map>
#include <vector>

enum class InputType
{
	next, // ���֍s���{�^��
	prev, // �O�ɖ߂�{�^��
	pause, // �|�[�Y�{�^��
	keyconfig,	// �L�[�R���t�B�O
	max	// �ő���̓C���f�b�N�X
};

// ���͑��u�J�e�S���[
enum class InputCategory
{
	keybd,	// �L�[�{�[�h
	pad,	// �p�b�h
	mouse	// �}�E�X
};

struct InputInfo
{
	InputCategory cat;	// ���͑��u�J�e�S���[
	int id; // ����ID
};

class InputState
{
private:
	// ���͏����X�V
	std::map<InputType, std::vector<InputInfo>>inputMapTable_;	// ���ۂ̓��͂ƃQ�[���{�^���̑Ή��e�[�u��

	std::vector<bool> currentInput_;	// ���݂̓��͏��(�����Ă��邩�����ĂȂ���)
	std::vector<bool> lastInput_;		// ���O�̓��͏��(���O�����Ă��邩�����ĂȂ���)

	/*int keyPadState;
	int lastKeyPadState;
	char keyState[256];
	char lastKeyState[256];*/

public:
	InputState();

	void Update();
	bool IsPressed(InputType type)const;
	bool IsTriggered(InputType type)const;
};