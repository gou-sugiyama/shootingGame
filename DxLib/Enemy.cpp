#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>

Location moveLocation[4] =
{
	{D_SCREEN_SIZE_X / 2,0},
	{D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 5},
	{D_SCREEN_SIZE_X - (D_ENEMY_RADIUS * 2),D_SCREEN_SIZE_Y / 5},
	{(D_ENEMY_RADIUS * 2),D_SCREEN_SIZE_Y / 5}
};

//-------------------------------
// コンストラクタ
//-------------------------------
Enemy::Enemy(Location* pLocation)
{
	//SphereColliderの初期化
	location = *pLocation;

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

	for (int i = 0; i < 4; i++)
	{
		DrawCircle(moveLocation[i].x, moveLocation[i].y, radius, 0x55AAAA);
	}
}


//-------------------------------
// 移動処理
//-------------------------------
void Enemy::Move()
{
	if (moving)
	{
		MoveToLocation(&moveLocation[1], 60 * 1);
	}
	else
	{
		Location distance = location - moveLocation[1];
		//moveAngle = atan2f(distance.x, distance.y);
		float y = sqrtf(3.0f);
		float x = 1;
		moveAngle = atan2f(x,y);
		float deg = 360 / M_PI * moveAngle;
		deg = deg;

	}
}

//-----------------------------------------------------------
// 指定された座標に移動する　フレーム数が0なら距離から計算
//-----------------------------------------------------------
bool Enemy::MoveToLocation(Location* pLocation, double frame)
{
	bool arrived = false; //指定された座標に到着したか
	if (!moving)
	{
	}



	return arrived;
}