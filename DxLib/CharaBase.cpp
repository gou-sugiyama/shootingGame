#include "CharaBase.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CharaBase::CharaBase()
{
	bullets = new BulletsManager();

}

//--------------------------------
// デストラクタ
//--------------------------------
CharaBase::~CharaBase()
{
	delete bullets;
}
