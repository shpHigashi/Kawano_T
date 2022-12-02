#pragma once

//#include "common.h"
#include<deque>

// プロトタイプ宣言
class Scene;
class InputState;

// シーン監視クラス
class SceneManager
{
private:
	// 今実行中のシーンを切り替えていきたいので
	// 参照ではなくポインタとして宣言
	std::deque<Scene*> scenes_;

public:
	// シーンの切り替えを行う
	void ChangeScene(Scene* scene);

	// シーンを上に積む
	// updateで時刻されるのは上に積まれたシーンのみ
	void PushScene(Scene* scene);

	// 一番上のシーンを削除する
	// ただし、その結果スタックが空になることのないように
	void PopScene();

	// 各シーンの更新を行う( 入力ステートの参照 )
	void Update(const InputState& input);

	// 各シーンの描画を行う
	void Draw();
};