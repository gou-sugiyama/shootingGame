#include "SceneManager.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
SceneManager::SceneManager()
{
	scene = nullptr;//new TitleScene();
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