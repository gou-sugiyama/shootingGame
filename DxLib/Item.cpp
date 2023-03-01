#include "Item.h"
#include "common.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
Item::Item(Location location, int type):SphereCollider(location,20)
{
	this->type = type;
	image = LoadGraph("images/life.png");
}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
Item::~Item()
{

}

//--------------------------------
// �X�V
//--------------------------------
void Item::Update()
{
	location.y++;
}

//--------------------------------
// �`��
//--------------------------------
void Item::Draw()const
{
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * 40, 0, image, TRUE);
}

//--------------------------------
// ��ʊO�ɂ��邩
//--------------------------------
bool Item::isScreenOut()
{
	//���̔���
	if (location.x < D_SCREEN_SIZE_X + radius && 0 - radius < location.x)
	{
		//�c�̔���
		if (location.y < D_SCREEN_SIZE_Y + radius && 0 - radius < location.y)
		{
			return false;
		}
	}

	return true;
}
