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
	vector<vector<int>> t_int;

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
	size_t size(int who_has)const { return bullets[who_has].size(); }
	BulletsBase* at(int who_has, int which)const { return bullets[who_has][which]; }

	//StraightBullet�̐���
	void ShotDefaultBullet(Location location, float radian, int chara_type);


	//��ʊO�̒e�̍폜
	void DeleteBulletScreenOut();

	//
	// TODO:�o���b�g�}�l�[�W���[�ɐÓI�֐������
	// �R���X�g���N�^���v���C�x�[�g�Ɏ��B
	// �L�����x�[�X�������ɁA�x�N�^�[������āA�L�����x�[�X�Ɋ�Â�bullets�����B
	// �L���������񂾂炻�̃o���b�g���J������B�isize��0�ɂȂ������j
	// vector<vector<Bullets*>> bullets����̎���������
	//
};

