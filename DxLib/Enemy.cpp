#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>


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

	SetMouseDispFlag(TRUE);

	InputCSV();
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
	//移動パターンに応じて動きを分ける
	switch (moveInfo[current].pattern)
	{
		//移動
	case 0:
		Move_t();
		break;

		//止まる
	case 1:
		waitTime++;
		if (moveInfo[current].waitTimeFrame <= waitTime)
		{
			waitTime = 0;
			current = moveInfo[current].next;
		}
		break;


	default:
		break;
	}

	if (moveInfo[current].attackPattern != 0)
	{
		//ここに弾打つ処理
		/*if(bulletCount < _ENEMY_BULLET_ALL_ && bullets[bulletCount] == nullptr)
		{
			if(moveInfo[current].attackpattern==1)
			{
				bullets[bulletsCount] = new StraightBullets(GetLocation(),Location{0,2});
			}
			else if (moveInfo[current].attackType == 2)
			{
				shotNum++;
				bullets[bulletCount] = new CircleBullert(GetLocation(),2.f,(20 * shotNum));
			}

		}
		*/
	}

}

//-------------------------------
// 描画
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
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "MoveInfo[%d] : pattern %d",current,moveInfo[current].pattern);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "MoveInfo[%d] : waitTimeFrame %d",current,moveInfo[current].waitTimeFrame);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "MoveInfo[%d] : attackPattern %d",current,moveInfo[current].attackPattern);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "MoveInfo[%d] : next %d",current,moveInfo[current].next);
		DrawFormatString(0, 200 + i++ * 20, 0xFF00DD, "waitTime : %d",waitTime);
	}
#endif // DEBUG

}


//-------------------------------
// 移動処理
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
*  radianメモ   *                
*  上：-1.57    *
*  右：0        *
*  下：1.57     *
*  左：3.14     *
*****************/

//-----------------------------------------------------------
// 自分の位置から、引数の座標までの角度を求める（ラジアン）
//-----------------------------------------------------------
float Enemy::GetRadian(Location* pLocation)
{
	float rad = 999;
	Location distance = *pLocation - location;

	//ラジアンを求める
	rad =  atan2f(distance.y, distance.x);

	return rad;
}

//-----------------------------------------------------------
// 角度に応じて真っすぐ移動する (ラジアン)
//-----------------------------------------------------------
void Enemy::MoveStraght(float radian)
{
	Location nextLocation = GetLocation();
	Location distance = moveInfo[current].targetLocation_t - GetLocation();

	//y座標の移動
	if (nextLocation.y != moveInfo[current].targetLocation_t.y)
	{
		if (fabsf(distance.y) > fabsf(speed * sinf(radian)))
		{
			nextLocation.y += (speed * sinf(radian));
		}
		else
		{
			nextLocation.y = moveInfo[current].targetLocation_t.y;
		}
	}

	//x座標の移動
	if (nextLocation.x != moveInfo[current].targetLocation_t.x)
	{
		if (fabsf(distance.x) > fabsf(speed * cosf(radian)))
		{
			nextLocation.x += speed * cosf(radian);
		}
		else
		{
			nextLocation.x = moveInfo[current].targetLocation_t.x;
		}
	}

	SetLocation(nextLocation);
}


//----------------------------------------
// 目的座標にいるか調べる
//----------------------------------------
bool Enemy::CheckArrival()
{
	bool isTargetLocation = false;



	return isTargetLocation;
}

//----------------------------------------
// ファイル読み込み
//----------------------------------------
void Enemy::InputCSV()
{
	std::string str_conma_buf;
	std::ifstream ifs("MoveInformation/moveInformation.csv");
	if (!ifs)
	{
		std::exit(1);
		return;
	}

	std::string line;
	for (int i = 0; !ifs.eof(); i++)
	{
		std::getline(ifs, line);
		std::istringstream i_stream(line);

		//Location
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].targetLocation_t.x = atof(str_conma_buf.c_str());
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].targetLocation_t.y = atof(str_conma_buf.c_str());
		//pattern
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].pattern = atoi(str_conma_buf.c_str());
		//waitTimeFrame
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].waitTimeFrame = atof(str_conma_buf.c_str());
		//attackPattern
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].attackPattern = atof(str_conma_buf.c_str());
		//next
		std::getline(i_stream, str_conma_buf, ',');
		moveInfo[i].next = atof(str_conma_buf.c_str());

	}
	ifs.close();
}

void Enemy::Move_t()
{
	Location nextLocation = GetLocation();

	if ((nextLocation.y == moveInfo[current].targetLocation_t.y) &&
		(nextLocation.x == moveInfo[current].targetLocation_t.x))
	{
		current = moveInfo[current].next;
	}
	else
	{
		if (nextLocation.y != moveInfo[current].targetLocation_t.y)
		{
			if (nextLocation.y < moveInfo[current].targetLocation_t.y)
			{
				nextLocation.y += speed_t.y;
				if ((GetLocation().y <= moveInfo[current].targetLocation_t.y) &&
					(moveInfo[current].targetLocation_t.y <= nextLocation.y))
				{
					nextLocation.y = moveInfo[current].targetLocation_t.y;
				}
			}
			else
			{
				nextLocation.y -= speed_t.y;
				if ((nextLocation.y <= moveInfo[current].targetLocation_t.y) &&
					(moveInfo[current].targetLocation_t.y <= GetLocation().y))
				{
					nextLocation.y = moveInfo[current].targetLocation_t.y;
				}
			}
		}


		if (nextLocation.x != moveInfo[current].targetLocation_t.x)
		{
			if (nextLocation.x < moveInfo[current].targetLocation_t.x)
			{
				nextLocation.x += speed_t.x;
				if ((GetLocation().x <= moveInfo[current].targetLocation_t.x) &&
					(moveInfo[current].targetLocation_t.x <= nextLocation.x))
				{
					nextLocation.x = moveInfo[current].targetLocation_t.x;
				}
			}
			else
			{
				nextLocation.x -= speed_t.x;
				if ((nextLocation.x <= moveInfo[current].targetLocation_t.x) &&
					(moveInfo[current].targetLocation_t.x <= GetLocation().x))
				{
					nextLocation.x = moveInfo[current].targetLocation_t.x;
				}
			}
		}
	}

	SetLocation(nextLocation);
}