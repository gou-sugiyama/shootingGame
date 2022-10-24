#include "SceneManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
SceneManager::SceneManager()
{
	scene = new GameMainScene();
}


//---------------------------------------------
// �X�V
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