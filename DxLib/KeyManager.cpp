#include "DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];
char KeyManager::nowKey[256];
int KeyManager::oldMouse;
int KeyManager::nowMouse;

//---------------------
// 更新
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
// キークリック
//----------------
bool KeyManager::OnKeyClicked(int Key)
{
	bool ret = (oldKey[Key] != TRUE) && (nowKey[Key] == TRUE);
	return ret;
}

//----------------
// キーリリース
//----------------
bool KeyManager::OnKeyReleased(int Key)
{
	bool ret = (oldKey[Key] == TRUE) && (nowKey[Key] != TRUE);
	return ret;
}

//----------------
// キープレス
//----------------
bool KeyManager::OnKeyPressed(int Key)
{
	bool ret = (oldKey[Key] == TRUE) && (nowKey[Key] == TRUE);
	return ret;
}

//----------------
// マウスクリック
//----------------
bool KeyManager::OnMouseClicked(int Key)
{
	return true;
}

//----------------
// マウスリリース
//----------------
bool KeyManager::OnMouseReleased(int Key)
{

	return true;
}

//----------------
// マウスプレス
//----------------
bool KeyManager::OnMousePressed(int Key)
{

	return true;
}
