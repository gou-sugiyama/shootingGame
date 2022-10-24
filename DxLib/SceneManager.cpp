#include "SceneManager.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
SceneManager::SceneManager()
{
	scene = nullptr;//new TitleScene();
}


//---------------------------------------------
// 更新
//---------------------------------------------
AbstractScene* SceneManager::Update()
{
	AbstractScene* pScene = scene->Update();
	if (scene != pScene)
	{
		delete scene;
		scene = pScene;
	}


	return pScene;
}