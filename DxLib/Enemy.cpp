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



////////////////////
struct MoveInformation
{
	Location targetLocation_t;
	int pattern;				//0:�ړ� 1:�~�܂�
	int next;
	int waitTimeFlame;
	int attackPattern;			//0:�U�����Ȃ��@1:�U������ 2:�ړ����Ȃ���U��
};

MoveInformation moveInfo[10] =
{
	{   640,150,0,1,  0,0},
	{1200.4,150,0,2,  0,0},
	{     0,  0,1,3,180,1},
	{  80.2,150,0,4,  0,2},
	{     0,  0,1,5,180,1},
	{1200.4,150,0,2,  0,1}

};

Location locations[3] =
{
	{   640,150},
	{1200.4,150},
	{  80.2,150},
};

int next[3] =
{
	1,
	2,
	1
};

int current = 1;
/////////////////////


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
	//Move_t();
	if (location != locations[current])
	{
		Move();
	}
	else
	{
		current = next[current];
	}
}

//-------------------------------
// �`��
//-------------------------------
void Enemy::Draw()
{
	DrawCircle(location.x, location.y, radius, 0xFF0000);

#define DEBUG
#ifdef DEBUG
	{
		int i = 0;
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "location.x : %.1lf", GetLocation().x);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "location.y : %.1lf", GetLocation().y);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "locations[%d].x : %.1lf", current,locations[current].x);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "locations[%d].y : %.1lf", current,locations[current].y);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "next[%d]:%d", current,next[current]);
	}
	for (int i = 0; i < 3; i++)
	{
		DrawCircle(locations[i].x, locations[i].y, radius, 0x55AAAA);
	}

#endif // DEBUG

}


//-------------------------------
// �ړ�����
//-------------------------------
void Enemy::Move()
{
	//MoveStraght(GetRadian(&locations[current]));

	MoveStraght(moveAngle);

	moveControlTime++;
	if (moveControlTime % 15 == 0)
	{
		moveAngle += M_PI / 12;
	}
	

}

/****************
*  radian����   *                
*  ��F-1.57    *
*  �E�F0        *
*  ���F1.57     *
*  ���F3.14     *
*****************/

//-----------------------------------------------------------
// �����̈ʒu����A�����̍��W�܂ł̊p�x�����߂�i���W�A���j
//-----------------------------------------------------------
float Enemy::GetRadian(Location* pLocation)
{
	float rad = 999;
	Location distance = *pLocation - location;

	//���W�A�������߂�
	rad =  atan2f(distance.y, distance.x);

	return rad;
}

//-----------------------------------------------------------
// �p�x�ɉ����Đ^�������ړ����� (���W�A��)
//-----------------------------------------------------------
void Enemy::MoveStraght(float radian)
{
	Location nextLocation = GetLocation();
	Location distance = locations[current] - GetLocation();

	//y���W�̈ړ�
	if (nextLocation.y != locations[current].y)
	{
		if (fabsf(distance.y) > fabsf(speed * sinf(radian)))
		{
			nextLocation.y += (speed * sinf(radian));
		}
		else
		{
			nextLocation.y = locations[current].y;
		}
	}

	//x���W�̈ړ�
	if (nextLocation.x != locations[current].x)
	{
		if (fabsf(distance.x) > fabsf(speed * cosf(radian)))
		{
			nextLocation.x += speed * cosf(radian);
		}
		else
		{
			nextLocation.x = locations[current].x;
		}
	}

	SetLocation(nextLocation);
}


//----------------------------------------
// �ړI���W�ɂ��邩���ׂ�
//----------------------------------------
bool Enemy::CheckArrival()
{
	bool isTargetLocation = false;



	return isTargetLocation;
}


void Enemy::Move_t()
{
	Location nextLocation = GetLocation();

	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];
	}
	else
	{
		if (nextLocation.y != locations[current].y)
		{
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed_t.y;
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					nextLocation.y = locations[current].y;
				}
			}
			else
			{
				nextLocation.y -= speed_t.y;
				if ((nextLocation.y <= locations[current].y) &&
					(locations[current].y <= GetLocation().y))
				{
					nextLocation.y = locations[current].y;
				}
			}
		}


		if (nextLocation.x != locations[current].x)
		{
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed_t.x;
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					nextLocation.x = locations[current].x;
				}
			}
			else
			{
				nextLocation.x -= speed_t.x;
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					nextLocation.x = locations[current].x;
				}
			}
		}
	}

	SetLocation(nextLocation);
}