#include "Troublesome.h"

//------------------------------
//コンストラクタ 
//------------------------------
Troublesome::Troublesome(Location location, const Player* player, float radius,
	int image, float speed, int hp, int point)
	:Enemy(location, radius, image, speed, hp, point)
{
	this->player = player;
	MakeTargetLocation();
	moveAngle = GetRadian(targetLocation);
}

//------------------------------
// デストラクタ
//------------------------------
Troublesome::~Troublesome()
{

}

//------------------------------
// 更新
//------------------------------
void Troublesome::Update()
{
	attackInterval--;

	Move();
	if (0 < waitTime && attackInterval < 0)
	{
		ShotAtPlayer();
	}
}

//------------------------------
// 移動
//------------------------------
void Troublesome::Move()
{
	if (0 < waitTime)
	{
		waitTime--;
		return;
	}

	if (MoveStraghtToTarget())
	{
		MakeTargetLocation();
		moveAngle = GetRadian(targetLocation);
		waitTime = 300;
	}

}

//-------------------------------------
// プレイヤーをねらって撃つ
//-------------------------------------
void Troublesome::ShotAtPlayer()
{
	attackInterval = SHOT_AT_PLAYER_INTERVAL;
	bulletsManager->
		ShotDefaultBullet(GetLocation(), GetRadian(player->GetLocation()), ENEMY_BULLETS);
}

//-----------------------------
// 目標座標の作成
//-----------------------------
void Troublesome::MakeTargetLocation()
{
	float distance = 0;
	do
	{
		targetLocation.x = GetRand(D_SCREEN_SIZE_X - (MOVE_AREA_MARGIN * 2));
		targetLocation.x += MOVE_AREA_MARGIN / 2;

		targetLocation.y = GetRand(MOVE_AREA_MAX_H - (MOVE_AREA_MARGIN));
		targetLocation.y += MOVE_AREA_MARGIN;

		Location buf = GetLocation() - targetLocation;

		distance = powf((buf.x * buf.x) - (buf.y * buf.y), 0.5);

	} while (distance < 200);
}