#pragma once
class AbstractScene
{
public:
	//�R���X�g���N�^
	AbstractScene();
	//�f�X�g���N�^
	virtual ~AbstractScene(){}

	//�X�V
	virtual AbstractScene* Update() = 0;
	//�`��
	virtual void Draw()const = 0;
};

