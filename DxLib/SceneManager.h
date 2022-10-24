#pragma once
#include "AbstractScene.h"
class SceneManager
{
private:
	AbstractScene* scene;
public:
	//コンストラクタ
	SceneManager();
	//デストラクタ
	~SceneManager()
	{
		delete scene;
	}

	//更新
	AbstractScene* Update();
	//描画
	void Draw()const { scene->Draw(); }
}
	

};

