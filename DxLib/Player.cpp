#include "Player.h"

//--------------------------------------
// コンストラクタ
//--------------------------------------
Player::Player()
	:CharaBase({ D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y * 2 / 3 },
		PLAYER_RADIUS - 3, PLAYER_SPEED)
{
	images[0] = LoadGraph("images/player.png");
	images[1] = LoadGraph("images/life.png");
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
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * PLAYER_RADIUS * 2, 0, images[0], TRUE);

	DrawLife();
}

//---------------------------------
// ライフの描画
//---------------------------------
void Player::DrawLife()const
{
	float x = 35;	//マージン10 + サイズの半分
	float y = 35;	//マージン10 + サイズの半分
	int size = 50;
	for (int i = 0; i < life; i++)
	{
		DrawRotaGraphF(x + size * i, y, 1.0 / 200 * size, 0, images[1], TRUE);
	}

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

//----------------------------------------
// 回復する
//----------------------------------------
void Player::Recovery(int amount)
{
	if (life < PLAYER_LIFE)
	{
		life += amount;
	}
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