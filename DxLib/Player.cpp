#include "Player.h"

//--------------------------------------
// �R���X�g���N�^
//--------------------------------------
Player::Player()
	:CharaBase({ D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y * 2 / 3 },
		PLAYER_RADIUS, PLAYER_SPEED)
{
	score = 0;
	life = PLAYER_LIFE;
}

//--------------------------------------
// �f�X�g���N�^
//--------------------------------------
Player::~Player()
{

}

//--------------------------------------
// �X�V
//--------------------------------------
void Player::Update()
{
	Controll();
	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT))
	{
		bulletsManager->
			ShotDefaultBullet(GetLocation(), PLAYER_BULLET_RADIAN, PLAYER_BULLETS);
	}
}

//--------------------------------------
// �`��
//--------------------------------------
void Player::Draw()
{
	DrawCircleAA(location.x, location.y, radius,30, 0xFF007B);
}

//---------------------------------
// �v���C���[�̑���
//---------------------------------
void Player::Controll()
{

	//��ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		location.y -= PLAYER_SPEED;
	}
	//���ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		location.y += PLAYER_SPEED;
	}
	//�E�ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		location.x += PLAYER_SPEED;
	}
	//��ړ�
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		location.x -= PLAYER_SPEED;
	}


}

//----------------------------------------
// �_���[�W���󂯂�
//----------------------------------------
void Player::ReceiveDamage(int damage)
{
	life -= damage;
}

//-----------------------------------
// �����Ă�H
//-----------------------------------
bool Player::LifeCheck()
{
	bool isAlive = true;
	if (life <= 0) isAlive = false;
	return isAlive;
}