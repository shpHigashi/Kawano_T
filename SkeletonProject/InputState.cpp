#include "InputState.h"
#include <DxLib.h>

InputState::InputState()
{
	inputMapTable_[InputType::next] = { {InputCategory::keybd, KEY_INPUT_RETURN},
										{InputCategory::pad, PAD_INPUT_R},
										{InputCategory::mouse, MOUSE_INPUT_LEFT} };
	
	inputMapTable_[InputType::prev] = { {InputCategory::keybd, KEY_INPUT_SPACE},
										{InputCategory::pad, PAD_INPUT_B}};
	
	inputMapTable_[InputType::pause] = { {InputCategory::keybd, KEY_INPUT_P},
										{InputCategory::pad, PAD_INPUT_L}};
	
	inputMapTable_[InputType::keyconfig] = { {InputCategory::keybd, KEY_INPUT_K},
											{InputCategory::pad, PAD_INPUT_Y} };
	currentInput_.resize(static_cast<int>(InputType::max));
	lastInput_.resize(static_cast<int>(InputType::max));
}

void InputState::Update()
{
	lastInput_= currentInput_;	// 直前の入力情報を記憶しておく

	char keystate[256];
	GetHitKeyStateAll(keystate);// 全キー情報を取得
	int padState = GetJoypadInputState(DX_INPUT_PAD1);	// パッド１コンの情報を取得する
	int mouseState = GetMouseInput();

	for (const auto& keymap : inputMapTable_)
	{
		for (const auto& input : keymap.second)
		{
			if (input.cat == InputCategory::keybd)
			{
				currentInput_[static_cast<int>(keymap.first)] = keystate[input.id];
			}
			else if(input.cat == InputCategory::pad)
			{
				currentInput_[static_cast<int>(keymap.first)] = padState & input.id;
			}
			else if (input.cat == InputCategory::mouse)
			{
				currentInput_[static_cast<int>(keymap.first)] = mouseState & input.id;
			}
		}
	}
}

bool InputState::IsPressed(InputType type)const
{
	return currentInput_[static_cast<int>(type)];
}

bool InputState::IsTriggered(InputType type)const
{
	return IsPressed(type) && !lastInput_[static_cast<int>(type)];
}