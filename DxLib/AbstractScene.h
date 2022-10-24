#pragma once
class AbstractScene
{
public:
	//コンストラクタ
	AbstractScene();
	//デストラクタ
	virtual ~AbstractScene(){}

	//更新
	virtual AbstractScene* Update() = 0;
	//描画
	virtual void Draw()const = 0;
};

