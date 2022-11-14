#include "common.h"
#include "Player.h"

//--------------------------------------
// コンストラクタ
//--------------------------------------
Player::Player()
{
	//SphereColliderの初期化
	location.x = D_SCREEN_SIZE_X / 2;		//画面中央
	location.y = D_SCREEN_SIZE_Y * 2 / 3;	//画面中央よりちょい下

	radius = D_PLAYER_RADIUS;

	//CharaBaseの初期化


	//Playerの初期化
	speed = D_PLAYER_SPEED;
}

//--------------------------------------
// デストラクタ
//--------------------------------------
Player::~Player()
{
	;
}

//--------------------------------------
// 更新
//--------------------------------------
void Player::Update()
{
	Controll();
}

//--------------------------------------
// 描画
//--------------------------------------
void Player::Draw()
{
	DrawCircle(location.x, location.y, radius, 0xFF007B);
}

//---------------------------------
// プレイヤーの操作
//---------------------------------
void Player::Controll()
{

	//上移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		location.y -= D_PLAYER_SPEED;
	}
	//下移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		location.y += D_PLAYER_SPEED;
	}
	//右移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		location.x += D_PLAYER_SPEED;
	}
	//上移動
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		location.x -= D_PLAYER_SPEED;
	}


}