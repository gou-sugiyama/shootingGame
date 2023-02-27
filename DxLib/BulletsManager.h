#pragma once
#include "common.h"
#include "StraightBullet.h"
#include "CharaBase.h"
#include "Enemy.h"
#include "Player.h"

#define D_DEFAULT_BULLETS_MAX 90
#define D_DEFAULT_DAMAGE 1
#define D_DEFAULT_SPEED 1.5f
#define D_DEFAULT_RADIUS 5
class BulletsManager
{
private:
	static BulletsManager* _Instance;
	vector<StraightBullet*>bullets;
	int bulletsMax = D_DEFAULT_BULLETS_MAX;

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
	void Hit(int bulletIndex);
	//�}�l�[�W���[����֐�
	int size()const { return bullets.size(); }
	BulletsBase* at(int bulletIndex)const { return bullets[bulletIndex]; }
	void SetMagazine(Enemy chara_base);
	void SetMagazine(Player chara_base);

	//StraightBullet�̐���
	void ShotDefaultBullet(Location location,float radian);


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

