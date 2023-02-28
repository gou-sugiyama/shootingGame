#include "Player.h"

//--------------------------------------
// コンストラクタ
//--------------------------------------
Player::Player()
	:CharaBase({ D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y * 2 / 3 },
		PLAYER_RADIUS, PLAYER_SPEED)
{
	score = 0;
	life = PLAYER_LIFE;
}

//--------------------------------------
// デストラクタ
//--------------------------------------
Player::~Player()
{

}

//--------------------------------------
// 更新
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
// 描画
//--------------------------------------
void Player::Draw()
{
	DrawCircleAA(location.x, location.y, radius,30, 0xFF007B);
}

//---------------------------------
// プレイヤーの操作
//---------------------------------
void Player::Controll()
{

	//上移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		location.y -= PLAYER_SPEED;
	}
	//下移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		location.y += PLAYER_SPEED;
	}
	//右移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		location.x += PLAYER_SPEED;
	}
	//上移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		location.x -= PLAYER_SPEED;
	}


}

//----------------------------------------
// ダメージを受ける
//----------------------------------------
void Player::ReceiveDamage(int damage)
{
	life -= damage;
}

//-----------------------------------
// 生きてる？
//-----------------------------------
bool Player::LifeCheck()
{
	bool isAlive = true;
	if (life <= 0) isAlive = false;
	return isAlive;
}