#include "Player.h"

//--------------------------------------
// �R���X�g���N�^
//--------------------------------------
Player::Player()
	:CharaBase({ D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y * 2 / 3 },0,
		PLAYER_RADIUS - 3, PLAYER_SPEED)
{
	image = LoadGraph("images/player.png");
	lifeImage = LoadGraph("images/life.png");
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
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * PLAYER_RADIUS * 5.0, 0, image, TRUE);

	DrawLife();
}

//---------------------------------
// ���C�t�̕`��
//---------------------------------
void Player::DrawLife()const
{
	float x = 35;	//�}�[�W��10 + �T�C�Y�̔���
	float y = 35;	//�}�[�W��10 + �T�C�Y�̔���
	int size = 50;
	for (int i = 0; i < life; i++)
	{
		DrawRotaGraphF(x + size * i, y, 1.0 / 200 * size, 0, lifeImage, TRUE);
	}

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

	if (location.x < 0)
	{
		location.x = 0;
	}
	if (D_SCREEN_SIZE_X < location.x)
	{
		location.x = D_SCREEN_SIZE_X;
	}
	if (location.y < 0)
	{
		location.y = 0;
	}
	if (D_SCREEN_SIZE_Y < location.y)
	{
		location.y = D_SCREEN_SIZE_Y;
	}
}

//----------------------------------------
// �_���[�W���󂯂�
//----------------------------------------
void Player::ReceiveDamage(int damage)
{
	life -= damage;
}

//----------------------------------------
// �񕜂���
//----------------------------------------
void Player::Recovery(int amount)
{
	if (life < PLAYER_LIFE)
	{
		life += amount;
	}
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