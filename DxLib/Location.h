#pragma once
typedef struct  Location
{
	float x;
	float y;

	Location operator +(Location location)
	{
		Location w;
		w.x = this->x + location.x;
		w.y = this->y + location.y;
		return w;
	}

	Location operator -(Location location)
	{
		Location w;
		w.x = this->x - location.x;
		w.y = this->y - location.y;
		return w;
	}
}Location;

