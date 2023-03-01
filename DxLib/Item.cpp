#include "Item.h"
#include "common.h"

//--------------------------------
// コンストラクタ
//--------------------------------
Item::Item(Location location, int type):SphereCollider(location,20)
{
	this->type = type;
	image = LoadGraph("images/life.png");
}

//--------------------------------
// デストラクタ
//--------------------------------
Item::~Item()
{

}

//--------------------------------
// 更新
//--------------------------------
void Item::Update()
{
	location.y++;
}

//--------------------------------
// 描画
//--------------------------------
void Item::Draw()const
{
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * 40, 0, image, TRUE);
}

//--------------------------------
// 画面外にいるか
//--------------------------------
bool Item::isScreenOut()
{
	//横の判定
	if (location.x < D_SCREEN_SIZE_X + radius && 0 - radius < location.x)
	{
		//縦の判定
		if (location.y < D_SCREEN_SIZE_Y + radius && 0 - radius < location.y)
		{
			return false;
		}
	}

	return true;
}
