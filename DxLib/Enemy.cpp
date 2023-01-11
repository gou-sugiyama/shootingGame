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

Location locations_t[3] =
{
	{640,   150},
	{1200.4,150},
	{ 80.2, 150},
};

int next_t[3] =
{
	1,
	2,
	1
};

int current = 0;
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
	//Move_t();
	if (location != targetLocation)
	{
		Move();
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

#define DEBUG
#ifdef DEBUG
	{
		int i = 0;
		DrawFormatString(0, 200 + i++ * 20, 0xffffff, "y�̈ړ��� sin() = %.1f", sin(GetRadian(&a)));
		DrawFormatString(0, 200 + i++ * 20, 0xffffff, "x�̈ړ��� cos() = %.1f", cos(GetRadian(&a)));
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "location.x : %.1lf", location.x);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "location.y : %.1lf", location.y);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "next[%d]:%d", current,next_t[current]);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "moveAngle : %.1lf", moveAngle);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "���Wa�Ƃ̊p�x�F%.1lf", GetRadian(&a));
	}
	for (int i = 0; i < 4; i++)
	{
		DrawCircle(moveLocation[i].x, moveLocation[i].y, radius, 0x55AAAA);
	}

#endif // DEBUG

}


//-------------------------------
// �ړ�����
//-------------------------------
void Enemy::Move()
{
	MoveStraght(GetRadian(&a));
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
	location.x += speed * cos(radian);
	location.y += speed * sin(radian);
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





void Enemy::Move_t()
{
	Location nextLocation = GetLocation();

	if ((nextLocation.y == locations_t[current].y) &&
		(nextLocation.x == locations_t[current].x))
	{
		current = next_t[current];
	}
	else
	{
		if (nextLocation.y != locations_t[current].y)
		{
			if (nextLocation.y < locations_t[current].y)
			{
				nextLocation.y += speed_t.y;
				if ((GetLocation().y <= locations_t[current].y) &&
					(locations_t[current].y <= nextLocation.y))
				{
					nextLocation.y = locations_t[current].y;
				}
			}
			else
			{
				nextLocation.y -= speed_t.y;
				if ((nextLocation.y <= locations_t[current].y) &&
					(locations_t[current].y <= GetLocation().y))
				{
					nextLocation.y = locations_t[current].y;
				}
			}
		}


		if (nextLocation.x != locations_t[current].x)
		{
			if (nextLocation.x < locations_t[current].x)
			{
				nextLocation.x += speed_t.x;
				if ((GetLocation().x <= locations_t[current].x) &&
					(locations_t[current].x <= nextLocation.x))
				{
					nextLocation.x = locations_t[current].x;
				}
			}
			else
			{
				nextLocation.x -= speed_t.x;
				if ((nextLocation.x <= locations_t[current].x) &&
					(locations_t[current].x <= GetLocation().x))
				{
					nextLocation.x = locations_t[current].x;
				}
			}
		}
	}

	SetLocation(nextLocation);
}