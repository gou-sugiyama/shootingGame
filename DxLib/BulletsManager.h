#pragma once
#include "common.h"
#include "StraightBullet.h"
#define D_DEFAULT_BULLETS_MAX 90
#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
class BulletsManager
{
private:
	vector<StraightBullet*>bullets;
	int bulletsMax = D_DEFAULT_BULLETS_MAX;

public:
	//コンストラクタ
	BulletsManager();
	BulletsManager(int bullets_max);
	//デストラクタ
	~BulletsManager();

	//更新
	void Update();
	//描画
	void Draw()const;
	//何かに当たった
	void Hit(int bulletIndex);
	//マネージャー操作関数
	int size()const { return bullets.size(); }
	const BulletsBase* at(int bulletIndex)const { return bullets[bulletIndex]; }

	//StraightBulletの生成
	void ShotDefaultBullet(Location location,float radian);


	//画面外の弾の削除
	void DeleteBulletScreenOut();


};

