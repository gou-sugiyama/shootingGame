#pragma once
#include "common.h"
#include "StraightBullet.h"
#include "CharaBase.h"


#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
#define PLAYER_BULLETS 0
#define ENEMY_BULLETS 1
class BulletsManager
{
private:
	static BulletsManager* _Instance;
	vector<vector<BulletsBase*>>bullets;

	int shotsImages[2][2];

	//�R���X�g���N�^
	BulletsManager();

public:
	static BulletsManager* GetInstance();
	static void Create();
	static void Delete();
	//�f�X�g���N�^
	~BulletsManager();

	//�X�V
	void Update();
	//�`��
	void Draw()const;
	//�����ɓ�������
	void Hit(int who_has,int which);
	//�}�l�[�W���[����֐�
	size_t size(int who_has)const;
	BulletsBase* at(int who_has, int which)const { return bullets[who_has][which]; }

	//StraightBullet�̐���
	void ShotDefaultBullet(Location location, float radian, int chara_type);


	//��ʊO�̒e�̍폜
	void DeleteBulletScreenOut();
};

