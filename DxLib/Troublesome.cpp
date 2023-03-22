#include "Troublesome.h"

//------------------------------
//�R���X�g���N�^ 
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
// �f�X�g���N�^
//------------------------------
Troublesome::~Troublesome()
{

}

//------------------------------
// �X�V
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
// �ړ�
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
// �v���C���[���˂���Č���
//-------------------------------------
void Troublesome::ShotAtPlayer()
{
	attackInterval = SHOT_AT_PLAYER_INTERVAL;
	bulletsManager->
		ShotDefaultBullet(GetLocation(), GetRadian(player->GetLocation()), ENEMY_BULLETS);
}

//-----------------------------
// �ڕW���W�̍쐬
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