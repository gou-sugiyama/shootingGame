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

	locationIndex = 0;
	targetLocation = moveLocation[locationIndex];

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
	MoveStraght(1);

}

//-----------------------------------------------------------
// �����̈ʒu����A�����̍��W�܂ł̊p�x�����߂�i���W�A���j
//-----------------------------------------------------------
float Enemy::GetRad(Location* pLocation)
{
	float rad = 999;
	Location distance = location - *pLocation;

	 rad =  atan2f(distance.x, distance.y);

	//�p�x�����߂�Ȃ炱������
	//deg = rad * (180 / M_PI);

	return rad;
}

//-----------------------------------------------------------
// �p�x�ɉ����Đ^�������ړ�����
//-----------------------------------------------------------
void Enemy::MoveStraght(float angle)
{
	location.x += cos(90/(180/M_PI));
	location.y += sin(90 / (180 / M_PI));
}

//-----------------------------------------------------------
// �ڕW���W�̍X�V �����F�V�����ړI���W
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
