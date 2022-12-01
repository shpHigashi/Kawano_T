#pragma once

enum class InputType
{
	next, // 次へ行くボタン
	prev // 前に戻るボタン
};

class InputState
{
private:
	int keyPadState;
	int lastKeyPadState;
	char keyState[256];
	char lastKeyState[256];

public:
	bool IsTriggered(InputType type)const;
	bool IsPressed(InputType type)const;
	void Update();
};