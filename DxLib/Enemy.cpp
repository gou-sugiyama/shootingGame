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
Location a;

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
	SetMouseDispFlag(TRUE);

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
		//Move();
	}
	else
	{
		UpdateTargetLocation();
	}

	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT))
	{
		int mouseX = 0;
		int mouseY = 0;
		GetMousePoint(&mouseX,&mouseY);
		a.x = mouseX;
		a.y = mouseY;
	}
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

#define DEBUG
#ifdef DEBUG
	{
		int i = 0;
		DrawFormatString(0, 200 + i++ * 20, 0xffffff, "y�̈ړ��� sin() = %.1f", sin(GetRadian(&a)));
		DrawFormatString(0, 200 + i++ * 20, 0xffffff, "x�̈ړ��� cos() = %.1f", cos(GetRadian(&a)));
	}
#endif // DEBUG

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
float Enemy::GetRadian(Location* pLocation)
{
	float rad = 999;
	Location distance = location - *pLocation;

	
	 rad =  atan2f(distance.x, distance.y);

	//�p�x�����߂�Ȃ炱������
	float deg = rad * (180 / M_PI);
	deg = deg;

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
