#include "Enemy.h"


//-------------------------------
// コンストラクタ
//-------------------------------
Enemy::Enemy()
{
	//SphereColliderの初期化
	location.x = D_SCREEN_SIZE_X / 2;
	location.y = 0;

	radius = D_ENEMY_RADIUS;

	//CharaBaseの初期化

	//Enemyの初期化
	hp = D_ENEMY_HP;
	point = D_ENEMY_POINT;

}

//-------------------------------
// デストラクタ
//-------------------------------
Enemy::~Enemy()
{
	;
}

//-------------------------------
// 更新
//-------------------------------
void Enemy::Update()
{
	Move();

}

//-------------------------------
// 描画
//-------------------------------
void Enemy::Draw()
{
	DrawCircle(location.x, location.y, radius, 0xFF0000);
}


//-------------------------------
// 移動処理
//-------------------------------
void Enemy::Move()
{
	location.y++;
}
