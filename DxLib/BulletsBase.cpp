#include "BulletsBase.h"

//----------------------------
// コンストラクタ
//----------------------------
BulletsBase::BulletsBase()
{
	//SphereColliderの初期化
	location.x = 0;
	location.y = 0;
	radius = 0;

}
//----------------------------
// デストラクタ
//----------------------------
BulletsBase::~BulletsBase()
{
	;
}

//-----------------------------------------------------
// 画面外か？　戻り値 true:画面外　false:画面内
//-----------------------------------------------------
bool BulletsBase::isScreenOut()
{
	//横の判定
	if (location.x < 0 - radius || D_SCREEN_SIZE_X + radius < location.x)
	{
		//縦の判定
		if (location.y < 0 - radius || D_SCREEN_SIZE_Y + radius < location.y)
		{
			return false;
		}
	}

	return true;
}

//----------------------------------------------
// 移動 ベクトルからx,yの成分に分解して加算する
//----------------------------------------------
void BulletsBase::Move()
{
	//角度が0なら真上に動く それ以外なら計算する
	if (angle == 0)
	{
		location.y -= amount;
	}
	else
	{
		//TODO : ここに成分分解の計算
	}
}