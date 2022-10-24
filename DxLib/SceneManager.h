#pragma once
#include "AbstractScene.h"
class SceneManager
{
private:
	AbstractScene* scene;
public:
	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager()
	{
		delete scene;
	}

	//�X�V
	AbstractScene* Update();
	//�`��
	void Draw()const { scene->Draw(); }
}
	

};

