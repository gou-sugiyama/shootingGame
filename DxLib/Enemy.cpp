#include "Enemy.h"


//-------------------------------
// �R���X�g���N�^
//-------------------------------
Enemy::Enemy()
{
	//SphereCollider�̏�����
	location.x = D_SCREEN_SIZE_X / 2;
	location.y = 0;

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
}


//-------------------------------
// �ړ�����
//-------------------------------
void Enemy::Move()
{
	location.y++;
}
