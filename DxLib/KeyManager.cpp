#include "DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];
char KeyManager::nowKey[256];
int KeyManager::oldMouse;
int KeyManager::nowMouse;

//---------------------
// �X�V
//---------------------
void KeyManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldKey[i] = nowKey[i];
	}
	if (GetHitKeyStateAll(nowKey) == -1)
	{
		throw - 1;
	}

	oldMouse = nowMouse;
	nowMouse = GetMouseInput();

}

//----------------
// �L�[�N���b�N
//----------------
bool KeyManager::OnKeyClicked(int Key)
{
	bool ret = (oldKey[Key] != TRUE) && (nowKey[Key] == TRUE);
	return ret;
}

//----------------
// �L�[�����[�X
//----------------
bool KeyManager::OnKeyReleased(int Key)
{
	bool ret = (oldKey[Key] == TRUE) && (nowKey[Key] != TRUE);
	return ret;
}

//----------------
// �L�[�v���X
//----------------
bool KeyManager::OnKeyPressed(int Key)
{
	bool ret = (oldKey[Key] == TRUE) && (nowKey[Key] == TRUE);
	return ret;
}

//----------------
// �}�E�X�N���b�N
//----------------
bool KeyManager::OnMouseClicked(int Key)
{
	return true;
}

//----------------
// �}�E�X�����[�X
//----------------
bool KeyManager::OnMouseReleased(int Key)
{

	return true;
}

//----------------
// �}�E�X�v���X
//----------------
bool KeyManager::OnMousePressed(int Key)
{

	return true;
}
