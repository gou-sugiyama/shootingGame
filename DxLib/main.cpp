#include"DxLib.h"
#include "Scene/SceneManager.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// タイトルを test に変更
	SetMainWindowText("C++シューティング");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetGraphMode(1280, 720, 32);

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理


	SetMouseDispFlag(FALSE);	//マウスカーソル非表示

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定


	//シーンマネージャーの確保
	SceneManager* sceneManager;
	sceneManager = new SceneManager();


	// ゲームループ
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESCキー*/ &&
		sceneManager->Update() != nullptr
		)
	{
		ClearDrawScreen();

		sceneManager->Draw();

		ScreenFlip();			// 裏画面の内容を表画面に反映
	}

	//シーンマネージャーの解放
	delete sceneManager;

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
