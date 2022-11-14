#include "common.h"
#include "Player.h"

//--------------------------------------
// �R���X�g���N�^
//--------------------------------------
Player::Player()
{
	//SphereCollider�̏�����
	location.x = D_SCREEN_SIZE_X / 2;		//��ʒ���
	location.y = D_SCREEN_SIZE_Y * 2 / 3;	//��ʒ�����肿�傢��

	radius = D_PLAYER_RADIUS;

	//CharaBase�̏�����


	//Player�̏�����
	speed = D_PLAYER_SPEED;
}

//--------------------------------------
// �f�X�g���N�^
//--------------------------------------
Player::~Player()
{
	;
}

//--------------------------------------
// �X�V
//--------------------------------------
void Player::Update()
{
	Controll();
}

//--------------------------------------
// �`��
//--------------------------------------
void Player::Draw()
{
	DrawCircle(location.x, location.y, radius, 0xFF007B);
}

//---------------------------------
// �v���C���[�̑���
//---------------------------------
void Player::Controll()
{

	//��ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		location.y -= D_PLAYER_SPEED;
	}
	//���ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		location.y += D_PLAYER_SPEED;
	}
	//�E�ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		location.x += D_PLAYER_SPEED;
	}
	//��ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		location.x -= D_PLAYER_SPEED;
	}


}