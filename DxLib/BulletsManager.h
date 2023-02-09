#pragma once
#include "common.h"
#include "StraightBullet.h"
#define D_DEFAULT_BULLETS_MAX 1
#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 100
class BulletsManager
{
private:
	vector<StraightBullet*>bullets;
	int bulletsMax = D_DEFAULT_BULLETS_MAX;

public:
	//�R���X�g���N�^
	BulletsManager();
	BulletsManager(int bullets_max);
	//�f�X�g���N�^
	~BulletsManager();

	//�X�V
	void Update();
	//�`��
	void Draw()const;

	//StraightBullet�̐���
	void ShotDefaultBullet(Location location,float radian);
};

