#pragma once

// プロトタイプ宣言
class Scene;
class InputState;

// シーン監視クラス
class SceneManager
{
private:
	// 今実行中のシーンを切り替えていきたいので
	// 参照ではなくポインタとして宣言
	Scene* scene_ = nullptr;

public:
	// シーンの切り替えを行う
	void ChangeScene(Scene* scene);

	// 各シーンの更新を行う( 入力ステートの参照 )
	void Update(const InputState& input);

	// 各シーンの描画を行う
	void Draw();
};