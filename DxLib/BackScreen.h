#pragma once
#define BACK_SCREEN_IMAGE_HEIGHT 1440
class BackScreen
{
private:
	int image;
	int scrollY;
	int scrollTime;
public:
	BackScreen();
	~BackScreen();

	void Update();
	void Draw()const;
};

