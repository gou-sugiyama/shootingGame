#include "CharaBase.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CharaBase::CharaBase()
{
	bullets = new BulletsManager();

}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
CharaBase::~CharaBase()
{
	delete bullets;
}
