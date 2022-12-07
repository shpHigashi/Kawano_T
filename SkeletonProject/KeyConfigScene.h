#pragma once
#include "Scene.h"

class InputState;
class SceneManager;

class KeyConfigScene : public Scene
{
public:
	KeyConfigScene(SceneManager& manager);
	void Update(const InputState& input);
	void Draw();
};

