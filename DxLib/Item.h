#pragma once
#include "SphereCollider.h"
class Item
	:public SphereCollider
{
private:
	int type;
	int image;
public:
	Item(Location location, int type);
	~Item();

	void Update();
	void Draw()const;

	bool isScreenOut();
};

