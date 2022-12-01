#include "InputState.h"
#include <DxLib.h>

void InputState::Update()
{
	// �O�̃t���[���̃L�[�󋵂��R�s�[
	for (int i = 0; i < _countof(lastKeyState); ++i)
	{
		lastKeyState[i] = keyState[i];
	}

	GetHitKeyStateAll(keyState);
}

bool InputState::IsTriggered(InputType type)const
{
	if (type == InputType::next)
	{
		return !lastKeyState[KEY_INPUT_RETURN] &&
			keyState[KEY_INPUT_RETURN];
	}
	else if (type == InputType::prev)
	{
		return !lastKeyState[KEY_INPUT_SPACE] &&
			keyState[KEY_INPUT_SPACE];
	}
}

bool InputState::IsPressed(InputType type)const
{
	if (type == InputType::next)
	{
		return keyState[KEY_INPUT_RETURN];
	}
	return false;
}