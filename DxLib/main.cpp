#include"DxLib.h"
#include "common.h"
//#include "KeyManager.h"
#include "Scene/SceneManager.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// �^�C�g���� test �ɕύX
	SetMainWindowText("C++�V���[�e�B���O");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetGraphMode(D_SCREEN_SIZE_X, D_SCREEN_SIZE_Y, 32);

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������


	SetMouseDispFlag(FALSE);	//�}�E�X�J�[�\����\��

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�


	//�V�[���}�l�[�W���[�̊m��
	SceneManager* sceneManager;
	sceneManager = new SceneManager();


	// �Q�[�����[�v
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESC�L�[*/ &&
		sceneManager->Update() != nullptr
		)
	{
		KeyManager::Update();
		ClearDrawScreen();

		sceneManager->Draw();

		if (KeyManager::OnKeyClicked(KEY_INPUT_Z))
		{
			DrawString(100, 100, "�ۂ��ۂ��ۂ��`", 0xFFFFFF);
		}
		if (KeyManager::OnKeyReleased(KEY_INPUT_Z))
		{
			DrawString(100, 100, "�͂ɂ��H", 0xFFFFFF);
		}
		if (KeyManager::OnKeyPressed(KEY_INPUT_Z))
		{
			DrawString(100, 100, "�΂����΂����΂��`��I", 0xFFFFFF);
		}
		
	 

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	//�V�[���}�l�[�W���[�̉��
	delete sceneManager;

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
