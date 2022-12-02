#include "SceneManager.h"
#include "Scene.h"

void SceneManager::ChangeScene(Scene* scene)
{	// シーンスタックが空ではなかったら...
	if (!scenes_.empty())
	{
		delete scenes_.front();	// topはてっぺんの要素を返す
		scenes_.pop_front();	// 一個減る→ふつうは０になる
	}

	scenes_.push_front(scene);// 一個増える
}

void SceneManager::PushScene(Scene* scene)
{
	scenes_.push_front(scene);// 一個増える
}

void SceneManager::PopScene()
{
	// popの結果、シーンが0にならないようにする
	if (scenes_.size() > 1)
	{
		delete scenes_.front();
		scenes_.pop_front();
	}
}

void SceneManager::Update(const InputState& input)
{
	scenes_.front()->Update(input);
}

void SceneManager::Draw()
{
	for (int i = scenes_.size() - 1; i >= 0; --i)
	{
		scenes_[i]->Draw();
	}
}