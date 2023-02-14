#pragma once
#include "common.h"
#include "StraightBullet.h"
#define D_DEFAULT_BULLETS_MAX 90
#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
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
	//�����ɓ�������
	void Hit(int bulletIndex);
	//�}�l�[�W���[����֐�
	int size()const { return bullets.size(); }
	const BulletsBase* at(int bulletIndex)const { return bullets[bulletIndex]; }

	//StraightBullet�̐���
	void ShotDefaultBullet(Location location,float radian);


	//��ʊO�̒e�̍폜
	void DeleteBulletScreenOut();


};

