#pragma once
#include "common.h"
#include "StraightBullet.h"
#include "CharaBase.h"
#include "Enemy.h"
#include "Player.h"

#define D_DEFAULT_BULLETS_MAX 90
#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
class BulletsManager
{
private:
	static BulletsManager* _Instance;
	vector<StraightBullet*>bullets;
	int bulletsMax = D_DEFAULT_BULLETS_MAX;

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
	void Hit(int bulletIndex);
	//マネージャー操作関数
	int size()const { return bullets.size(); }
	BulletsBase* at(int bulletIndex)const { return bullets[bulletIndex]; }
	void SetMagazine(Enemy chara_base);
	void SetMagazine(Player chara_base);

	//StraightBulletの生成
	void ShotDefaultBullet(Location location,float radian);


	//画面外の弾の削除
	void DeleteBulletScreenOut();

	//
	// TODO:バレットマネージャーに静的関数を作る
	// コンストラクタをプライベートに持つ。
	// キャラベースを引数に、ベクターを作って、キャラベースに基づくbulletsを作る。
	// キャラが死んだらそのバレットを開放する。（sizeが0になった時）
	// vector<vector<Bullets*>> bulletsこれの実現させる
	//
};

