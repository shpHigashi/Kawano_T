#include <DxLib.h>
#include <cassert>
#include <array>
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputState.h"
#include "DrawFunctions.h"

void Function(int count, int value)
{
	DrawFormatString(50, 50, GetColor(255, 255, 255), L"count=%d", count);
	DrawFormatString(50, 70, GetColor(255, 255, 255), L"value=%d", value);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// âÊñ ÉTÉCÉYÇÃê›íË
	SetGraphMode(480, 480, 32);

	ChangeWindowMode(true);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	
	int count = 0;
	int value = 0;
	++value;

	int handle = 0;
	handle = my::MyLoadGraph(L"rime.jpg");

	InputState input;
	SceneManager sceneManager;
	sceneManager.ChangeScene(new TitleScene(sceneManager));

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		input.Update();

		sceneManager.Update(input);
		sceneManager.Draw();

		//Function(count++, value);
		ScreenFlip();
	}

	DxLib_End();
	
	return 0;
}