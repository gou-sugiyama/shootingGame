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
// �R���X�g���N�^
//-------------------------------
Enemy::Enemy(Location* pLocation)
{
	//SphereCollider�̏�����
	location = *pLocation;

	radius = D_ENEMY_RADIUS;

	//CharaBase�̏�����

	//Enemy�̏�����
	hp = D_ENEMY_HP;
	point = D_ENEMY_POINT;

}

//-------------------------------
// �f�X�g���N�^
//-------------------------------
Enemy::~Enemy()
{
	;
}

//-------------------------------
// �X�V
//-------------------------------
void Enemy::Update()
{
	Move();

}

//-------------------------------
// �`��
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
// �ړ�����
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
// �w�肳�ꂽ���W�Ɉړ�����@�t���[������0�Ȃ狗������v�Z
//-----------------------------------------------------------
bool Enemy::MoveToLocation(Location* pLocation, double frame)
{
	bool arrived = false; //�w�肳�ꂽ���W�ɓ���������
	if (!moving)
	{
	}



	return arrived;
}