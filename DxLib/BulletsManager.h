#pragma once
#include "common.h"
#include "StraightBullet.h"
#include "CharaBase.h"


#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
#define PLAYER_BULLETS 0
#define ENEMY_BULLETS 1
class BulletsManager
{
private:
	static BulletsManager* _Instance;
	vector<vector<BulletsBase*>>bullets;

	int shotsImages[2][2];

	//コンストラクタ
	BulletsManager();

public:
	static BulletsManager* GetInstance();
	static void Create();
	static void Delete();
	//デストラクタ
	~BulletsManager();

	//更新
	void Update();
	//描画
	void Draw()const;
	//何かに当たった
	void Hit(int who_has,int which);
	//マネージャー操作関数
	size_t size(int who_has)const;
	BulletsBase* at(int who_has, int which)const { return bullets[who_has][which]; }

	//StraightBulletの生成
	void ShotDefaultBullet(Location location, float radian, int chara_type);


	//画面外の弾の削除
	void DeleteBulletScreenOut();
};

