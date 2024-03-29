#include "SceneManager.h"
#include "TitleScene.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
SceneManager::SceneManager()
{
	scene = new TitleScene();
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