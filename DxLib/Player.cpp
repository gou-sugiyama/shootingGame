#include "Player.h"

//--------------------------------------
// コンストラクタ
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
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * PLAYER_RADIUS * 5.0, 0, image, TRUE);

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
		DrawRotaGraphF(x + size * i, y, 1.0 / 200 * size, 0, lifeImage, TRUE);
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