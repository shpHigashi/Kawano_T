#pragma once

#include <map>
#include <vector>

enum class InputType
{
	next, // 次へ行くボタン
	prev, // 前に戻るボタン
	pause, // ポーズボタン
	keyconfig,	// キーコンフィグ
	max	// 最大入力インデックス
};

// 入力装置カテゴリー
enum class InputCategory
{
	keybd,	// キーボード
	pad,	// パッド
	mouse	// マウス
};

struct InputInfo
{
	InputCategory cat;	// 入力装置カテゴリー
	int id; // 入力ID
};

class InputState
{
private:
	// 入力情報を更新
	std::map<InputType, std::vector<InputInfo>>inputMapTable_;	// 実際の入力とゲームボタンの対応テーブル

	std::vector<bool> currentInput_;	// 現在の入力情報(押しているか押してないか)
	std::vector<bool> lastInput_;		// 直前の入力情報(直前押しているか押してないか)

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