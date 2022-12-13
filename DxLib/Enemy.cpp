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


int dx = 640;
int dy = -10;

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

	locationIndex = 0;
	targetLocation = moveLocation[locationIndex];

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
	if (location != targetLocation)
	{
		Move();
	}
	else
	{
		UpdateTargetLocation();
	}


	Location a;
	a.x = dx;
	a.y = dy;
	GetRad(&a);
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
	MoveStraght(1);

}

//-----------------------------------------------------------
// 自分の位置から、引数の座標までの角度を求める（ラジアン）
//-----------------------------------------------------------
float Enemy::GetRad(Location* pLocation)
{
	float rad = 999;
	Location distance = location - *pLocation;

	 rad =  atan2f(distance.x, distance.y);

	//角度を求めるならこっち↓
	//deg = rad * (180 / M_PI);

	return rad;
}

//-----------------------------------------------------------
// 角度に応じて真っすぐ移動する
//-----------------------------------------------------------
void Enemy::MoveStraght(float angle)
{
	location.x += cos(90/(180/M_PI));
	location.y += sin(90 / (180 / M_PI));
}

//-----------------------------------------------------------
// 目標座標の更新 引数：新しい目的座標
//-----------------------------------------------------------
void Enemy::UpdateTargetLocation()
{
	if (locationIndex < D_ENEMY_MOVELOOP_END)
	{
		locationIndex++;
	}
	else
	{
		locationIndex -= (D_ENEMY_MOVELOOP_END - D_ENEMY_MOVELOOP_START);
	}

	targetLocation = moveLocation[locationIndex];
}
